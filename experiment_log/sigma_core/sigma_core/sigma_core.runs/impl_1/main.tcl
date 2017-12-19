proc start_step { step } {
  set stopFile ".stop.rst"
  if {[file isfile .stop.rst]} {
    puts ""
    puts "*** Halting run - EA reset detected ***"
    puts ""
    puts ""
    return -code error
  }
  set beginFile ".$step.begin.rst"
  set platform "$::tcl_platform(platform)"
  set user "$::tcl_platform(user)"
  set pid [pid]
  set host ""
  if { [string equal $platform unix] } {
    if { [info exist ::env(HOSTNAME)] } {
      set host $::env(HOSTNAME)
    }
  } else {
    if { [info exist ::env(COMPUTERNAME)] } {
      set host $::env(COMPUTERNAME)
    }
  }
  set ch [open $beginFile w]
  puts $ch "<?xml version=\"1.0\"?>"
  puts $ch "<ProcessHandle Version=\"1\" Minor=\"0\">"
  puts $ch "    <Process Command=\".planAhead.\" Owner=\"$user\" Host=\"$host\" Pid=\"$pid\">"
  puts $ch "    </Process>"
  puts $ch "</ProcessHandle>"
  close $ch
}

proc end_step { step } {
  set endFile ".$step.end.rst"
  set ch [open $endFile w]
  close $ch
}

proc step_failed { step } {
  set endFile ".$step.error.rst"
  set ch [open $endFile w]
  close $ch
}

set_msg_config -id {HDL 9-1061} -limit 100000
set_msg_config -id {HDL 9-1654} -limit 100000

start_step place_design
set rc [catch {
  create_msg_db place_design.pb
  open_checkpoint main_opt.dcp
  set_property webtalk.parent_dir /home/jvarred/Desktop/sigma_core/sigma_core/sigma_core.cache/wt [current_project]
  catch {write_hwdef -file main.hwdef}
  place_design 
  write_checkpoint -force main_placed.dcp
  report_io -file main_io_placed.rpt
  report_utilization -file main_utilization_placed.rpt -pb main_utilization_placed.pb
  report_control_sets -verbose -file main_control_sets_placed.rpt
  close_msg_db -file place_design.pb
} RESULT]
if {$rc} {
  step_failed place_design
  return -code error $RESULT
} else {
  end_step place_design
}

start_step route_design
set rc [catch {
  create_msg_db route_design.pb
  route_design 
  write_checkpoint -force main_routed.dcp
  report_drc -file main_drc_routed.rpt -pb main_drc_routed.pb
  report_timing_summary -warn_on_violation -max_paths 10 -file main_timing_summary_routed.rpt -rpx main_timing_summary_routed.rpx
  report_power -file main_power_routed.rpt -pb main_power_summary_routed.pb
  report_route_status -file main_route_status.rpt -pb main_route_status.pb
  report_clock_utilization -file main_clock_utilization_routed.rpt
  close_msg_db -file route_design.pb
} RESULT]
if {$rc} {
  step_failed route_design
  return -code error $RESULT
} else {
  end_step route_design
}

