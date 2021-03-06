# 
# Synthesis run script generated by Vivado
# 

set_msg_config -id {HDL 9-1061} -limit 100000
set_msg_config -id {HDL 9-1654} -limit 100000
create_project -in_memory -part xc7z010clg400-1

set_param project.compositeFile.enableAutoGeneration 0
set_param synth.vivado.isSynthRun true
set_msg_config -source 4 -id {IP_Flow 19-2162} -severity warning -new_severity info
set_property webtalk.parent_dir /home/jvarred/Desktop/sigma_core/sigma_implementation/my_test.cache/wt [current_project]
set_property parent.project_path /home/jvarred/Desktop/sigma_core/sigma_implementation/my_test.xpr [current_project]
set_property default_lib xil_defaultlib [current_project]
set_property target_language Verilog [current_project]
set_property ip_repo_paths {
  /home/jvarred/Desktop/parallella-fpga-dummy-io/ip_repo
  /home/jvarred/Desktop/HLS
} [current_project]
set_property vhdl_version vhdl_2k [current_fileset]
add_files /home/jvarred/Desktop/sigma_core/sigma_implementation/my_test.srcs/sources_1/bd/top/top.bd
set_property used_in_implementation false [get_files -all /home/jvarred/Desktop/sigma_core/sigma_implementation/my_test.srcs/sources_1/bd/top/ip/top_processing_system7_0_0/top_processing_system7_0_0.xdc]
set_property used_in_implementation false [get_files -all /home/jvarred/Desktop/sigma_core/sigma_implementation/my_test.srcs/sources_1/bd/top/ip/top_doGain_0_0/constraints/doGain_ooc.xdc]
set_property used_in_implementation false [get_files -all /home/jvarred/Desktop/sigma_core/sigma_implementation/my_test.srcs/sources_1/bd/top/ip/top_rst_processing_system7_0_100M_0/top_rst_processing_system7_0_100M_0_board.xdc]
set_property used_in_implementation false [get_files -all /home/jvarred/Desktop/sigma_core/sigma_implementation/my_test.srcs/sources_1/bd/top/ip/top_rst_processing_system7_0_100M_0/top_rst_processing_system7_0_100M_0.xdc]
set_property used_in_implementation false [get_files -all /home/jvarred/Desktop/sigma_core/sigma_implementation/my_test.srcs/sources_1/bd/top/ip/top_rst_processing_system7_0_100M_0/top_rst_processing_system7_0_100M_0_ooc.xdc]
set_property used_in_implementation false [get_files -all /home/jvarred/Desktop/sigma_core/sigma_implementation/my_test.srcs/sources_1/bd/top/ip/top_axi_dma_0_0/top_axi_dma_0_0_ooc.xdc]
set_property used_in_implementation false [get_files -all /home/jvarred/Desktop/sigma_core/sigma_implementation/my_test.srcs/sources_1/bd/top/ip/top_axi_dma_0_0/top_axi_dma_0_0.xdc]
set_property used_in_implementation false [get_files -all /home/jvarred/Desktop/sigma_core/sigma_implementation/my_test.srcs/sources_1/bd/top/ip/top_axi_dma_0_0/top_axi_dma_0_0_clocks.xdc]
set_property used_in_implementation false [get_files -all /home/jvarred/Desktop/sigma_core/sigma_implementation/my_test.srcs/sources_1/bd/top/ip/top_xbar_0/top_xbar_0_ooc.xdc]
set_property used_in_implementation false [get_files -all /home/jvarred/Desktop/sigma_core/sigma_implementation/my_test.srcs/sources_1/bd/top/ip/top_xbar_1/top_xbar_1_ooc.xdc]
set_property used_in_implementation false [get_files -all /home/jvarred/Desktop/sigma_core/sigma_implementation/my_test.srcs/sources_1/bd/top/ip/top_auto_pc_1/top_auto_pc_1_ooc.xdc]
set_property used_in_implementation false [get_files -all /home/jvarred/Desktop/sigma_core/sigma_implementation/my_test.srcs/sources_1/bd/top/ip/top_auto_pc_2/top_auto_pc_2_ooc.xdc]
set_property used_in_implementation false [get_files -all /home/jvarred/Desktop/sigma_core/sigma_implementation/my_test.srcs/sources_1/bd/top/ip/top_auto_us_0/top_auto_us_0_ooc.xdc]
set_property used_in_implementation false [get_files -all /home/jvarred/Desktop/sigma_core/sigma_implementation/my_test.srcs/sources_1/bd/top/ip/top_auto_us_0/top_auto_us_0_clocks.xdc]
set_property used_in_implementation false [get_files -all /home/jvarred/Desktop/sigma_core/sigma_implementation/my_test.srcs/sources_1/bd/top/ip/top_auto_us_1/top_auto_us_1_ooc.xdc]
set_property used_in_implementation false [get_files -all /home/jvarred/Desktop/sigma_core/sigma_implementation/my_test.srcs/sources_1/bd/top/ip/top_auto_us_1/top_auto_us_1_clocks.xdc]
set_property used_in_implementation false [get_files -all /home/jvarred/Desktop/sigma_core/sigma_implementation/my_test.srcs/sources_1/bd/top/top_ooc.xdc]
set_property is_locked true [get_files /home/jvarred/Desktop/sigma_core/sigma_implementation/my_test.srcs/sources_1/bd/top/top.bd]

read_verilog -library xil_defaultlib /home/jvarred/Desktop/sigma_core/sigma_implementation/my_test.srcs/sources_1/imports/hdl/top_wrapper.v
read_xdc /home/jvarred/Desktop/sigma_core/sigma_implementation/my_test.srcs/constrs_1/imports/constraints/parallella_z70x0_loc.xdc
set_property used_in_implementation false [get_files /home/jvarred/Desktop/sigma_core/sigma_implementation/my_test.srcs/constrs_1/imports/constraints/parallella_z70x0_loc.xdc]

read_xdc dont_touch.xdc
set_property used_in_implementation false [get_files dont_touch.xdc]
synth_design -top top_wrapper -part xc7z010clg400-1
write_checkpoint -noxdef top_wrapper.dcp
catch { report_utilization -file top_wrapper_utilization_synth.rpt -pb top_wrapper_utilization_synth.pb }
