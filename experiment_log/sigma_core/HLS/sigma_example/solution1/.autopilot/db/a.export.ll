; ModuleID = '/home/jvarred/Desktop/HLS/sigma_example/solution1/.autopilot/db/a.o.2.bc'
target datalayout = "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@llvm_global_ctors_1 = appending global [1 x void ()*] [void ()* @_GLOBAL__I_a]
@llvm_global_ctors_0 = appending global [1 x i32] [i32 65535]
@doGain_str = internal unnamed_addr constant [7 x i8] c"doGain\00"
@p_str6 = private unnamed_addr constant [12 x i8] c"hls_label_2\00", align 1
@p_str5 = private unnamed_addr constant [4 x i8] c"odd\00", align 1
@p_str4 = private unnamed_addr constant [5 x i8] c"even\00", align 1
@p_str3 = private unnamed_addr constant [12 x i8] c"hls_label_0\00", align 1
@p_str2 = private unnamed_addr constant [12 x i8] c"hls_label_1\00", align 1
@p_str1 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@p_str = private unnamed_addr constant [5 x i8] c"axis\00", align 1

declare void @llvm.dbg.value(metadata, i64, metadata) nounwind readnone

declare void @llvm.dbg.declare(metadata, metadata) nounwind readnone

define void @doGain(i32* %inStream_V_data_V, i4* %inStream_V_keep_V, i4* %inStream_V_strb_V, i2* %inStream_V_user_V, i1* %inStream_V_last_V, i5* %inStream_V_id_V, i6* %inStream_V_dest_V, i32* %outStream_V_data_V, i4* %outStream_V_keep_V, i4* %outStream_V_strb_V, i2* %outStream_V_user_V, i1* %outStream_V_last_V, i5* %outStream_V_id_V, i6* %outStream_V_dest_V) {
.preheader37.preheader:
  call void (...)* @_ssdm_op_SpecBitsMap(i32* %inStream_V_data_V), !map !7
  call void (...)* @_ssdm_op_SpecBitsMap(i4* %inStream_V_keep_V), !map !11
  call void (...)* @_ssdm_op_SpecBitsMap(i4* %inStream_V_strb_V), !map !15
  call void (...)* @_ssdm_op_SpecBitsMap(i2* %inStream_V_user_V), !map !19
  call void (...)* @_ssdm_op_SpecBitsMap(i1* %inStream_V_last_V), !map !23
  call void (...)* @_ssdm_op_SpecBitsMap(i5* %inStream_V_id_V), !map !27
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %inStream_V_dest_V), !map !31
  call void (...)* @_ssdm_op_SpecBitsMap(i32* %outStream_V_data_V), !map !35
  call void (...)* @_ssdm_op_SpecBitsMap(i4* %outStream_V_keep_V), !map !39
  call void (...)* @_ssdm_op_SpecBitsMap(i4* %outStream_V_strb_V), !map !43
  call void (...)* @_ssdm_op_SpecBitsMap(i2* %outStream_V_user_V), !map !47
  call void (...)* @_ssdm_op_SpecBitsMap(i1* %outStream_V_last_V), !map !51
  call void (...)* @_ssdm_op_SpecBitsMap(i5* %outStream_V_id_V), !map !55
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %outStream_V_dest_V), !map !59
  call void (...)* @_ssdm_op_SpecTopModule([7 x i8]* @doGain_str) nounwind
  %valIn_data_V = alloca [10000 x i32], align 4
  %valIn_keep_V = alloca [10000 x i4], align 1
  %valIn_strb_V = alloca [10000 x i4], align 1
  %valIn_user_V = alloca [10000 x i2], align 1
  %valIn_last_V = alloca [10000 x i1], align 1
  %valIn_id_V = alloca [10000 x i5], align 1
  %valIn_dest_V = alloca [10000 x i6], align 1
  call void (...)* @_ssdm_op_SpecInterface(i32* %outStream_V_data_V, i4* %outStream_V_keep_V, i4* %outStream_V_strb_V, i2* %outStream_V_user_V, i1* %outStream_V_last_V, i5* %outStream_V_id_V, i6* %outStream_V_dest_V, [5 x i8]* @p_str, i32 0, i32 0, i32 0, i32 0, [1 x i8]* @p_str1, [1 x i8]* @p_str1, [1 x i8]* @p_str1, [1 x i8]* @p_str1) nounwind
  call void (...)* @_ssdm_op_SpecInterface(i32* %inStream_V_data_V, i4* %inStream_V_keep_V, i4* %inStream_V_strb_V, i2* %inStream_V_user_V, i1* %inStream_V_last_V, i5* %inStream_V_id_V, i6* %inStream_V_dest_V, [5 x i8]* @p_str, i32 0, i32 0, i32 0, i32 0, [1 x i8]* @p_str1, [1 x i8]* @p_str1, [1 x i8]* @p_str1, [1 x i8]* @p_str1) nounwind
  br label %.preheader37

.preheader37:                                     ; preds = %0, %.preheader37.preheader
  %idx = phi i14 [ %idx_1, %0 ], [ 0, %.preheader37.preheader ]
  %exitcond1 = icmp eq i14 %idx, -6384
  %idx_1 = add i14 %idx, 1
  br i1 %exitcond1, label %.preheader36.0, label %0

; <label>:0                                       ; preds = %.preheader37
  %empty = call i32 (...)* @_ssdm_op_SpecLoopTripCount(i64 10000, i64 10000, i64 10000)
  %tmp_1 = call i32 (...)* @_ssdm_op_SpecRegionBegin([12 x i8]* @p_str2)
  call void (...)* @_ssdm_op_SpecPipeline(i32 1, i32 1, i32 1, i32 0, [1 x i8]* @p_str1) nounwind
  %tmp = zext i14 %idx to i64
  %empty_3 = call { i32, i4, i4, i2, i1, i5, i6 } @_ssdm_op_Read.axis.volatile.i32P.i4P.i4P.i2P.i1P.i5P.i6P(i32* %inStream_V_data_V, i4* %inStream_V_keep_V, i4* %inStream_V_strb_V, i2* %inStream_V_user_V, i1* %inStream_V_last_V, i5* %inStream_V_id_V, i6* %inStream_V_dest_V)
  %tmp_data_V = extractvalue { i32, i4, i4, i2, i1, i5, i6 } %empty_3, 0
  %tmp_keep_V = extractvalue { i32, i4, i4, i2, i1, i5, i6 } %empty_3, 1
  %tmp_strb_V = extractvalue { i32, i4, i4, i2, i1, i5, i6 } %empty_3, 2
  %tmp_user_V = extractvalue { i32, i4, i4, i2, i1, i5, i6 } %empty_3, 3
  %tmp_last_V = extractvalue { i32, i4, i4, i2, i1, i5, i6 } %empty_3, 4
  %tmp_id_V = extractvalue { i32, i4, i4, i2, i1, i5, i6 } %empty_3, 5
  %tmp_dest_V = extractvalue { i32, i4, i4, i2, i1, i5, i6 } %empty_3, 6
  %valIn_data_V_addr = getelementptr [10000 x i32]* %valIn_data_V, i64 0, i64 %tmp
  store i32 %tmp_data_V, i32* %valIn_data_V_addr, align 4
  %valIn_keep_V_addr = getelementptr [10000 x i4]* %valIn_keep_V, i64 0, i64 %tmp
  store i4 %tmp_keep_V, i4* %valIn_keep_V_addr, align 4
  %valIn_strb_V_addr = getelementptr [10000 x i4]* %valIn_strb_V, i64 0, i64 %tmp
  store i4 %tmp_strb_V, i4* %valIn_strb_V_addr, align 1
  %valIn_user_V_addr = getelementptr [10000 x i2]* %valIn_user_V, i64 0, i64 %tmp
  store i2 %tmp_user_V, i2* %valIn_user_V_addr, align 2
  %valIn_last_V_addr = getelementptr [10000 x i1]* %valIn_last_V, i64 0, i64 %tmp
  store i1 %tmp_last_V, i1* %valIn_last_V_addr, align 1
  %valIn_id_V_addr = getelementptr [10000 x i5]* %valIn_id_V, i64 0, i64 %tmp
  store i5 %tmp_id_V, i5* %valIn_id_V_addr, align 4
  %valIn_dest_V_addr = getelementptr [10000 x i6]* %valIn_dest_V, i64 0, i64 %tmp
  store i6 %tmp_dest_V, i6* %valIn_dest_V_addr, align 1
  %empty_4 = call i32 (...)* @_ssdm_op_SpecRegionEnd([12 x i8]* @p_str2, i32 %tmp_1)
  br label %.preheader37

.preheader36.0:                                   ; preds = %.preheader37, %.loopexit.loopexit1.1
  %stage1 = phi i14 [ %stage_1, %.loopexit.loopexit1.1 ], [ 0, %.preheader37 ]
  %exitcond2 = icmp eq i14 %stage1, -6384
  br i1 %exitcond2, label %.preheader, label %.preheader33.preheader.0

.loopexit.loopexit.0:                             ; preds = %.preheader33.0
  %empty_5 = call i32 (...)* @_ssdm_op_SpecRegionEnd([12 x i8]* @p_str3, i32 %tmp_2)
  %tmp_7 = call i32 (...)* @_ssdm_op_SpecRegionBegin([12 x i8]* @p_str3)
  br label %.preheader34.1

.preheader33.0:                                   ; preds = %.preheader33.preheader.0, %._crit_edge41.0
  %i_1 = phi i14 [ %i_2, %._crit_edge41.0 ], [ 1, %.preheader33.preheader.0 ]
  %tmp_8 = icmp ult i14 %i_1, -6384
  br i1 %tmp_8, label %1, label %.loopexit.loopexit.0

._crit_edge41.0:                                  ; preds = %2, %1
  %empty_6 = call i32 (...)* @_ssdm_op_SpecRegionEnd([4 x i8]* @p_str5, i32 %tmp_4)
  %i_2 = add i14 %i_1, 2
  br label %.preheader33.0

; <label>:1                                       ; preds = %.preheader33.0
  %empty_7 = call i32 (...)* @_ssdm_op_SpecLoopTripCount(i64 5000, i64 5000, i64 5000)
  call void (...)* @_ssdm_op_SpecLoopName([4 x i8]* @p_str5) nounwind
  %tmp_4 = call i32 (...)* @_ssdm_op_SpecRegionBegin([4 x i8]* @p_str5)
  call void (...)* @_ssdm_op_SpecPipeline(i32 1, i32 1, i32 1, i32 0, [1 x i8]* @p_str1) nounwind
  %tmp_s = zext i14 %i_1 to i64
  %tmp_10 = add i14 %i_1, -1
  %tmp_11 = zext i14 %tmp_10 to i64
  %valIn_data_V_addr_2 = getelementptr [10000 x i32]* %valIn_data_V, i64 0, i64 %tmp_s
  %valIn_data_V_load = load i32* %valIn_data_V_addr_2, align 4
  %valIn_data_V_addr_3 = getelementptr [10000 x i32]* %valIn_data_V, i64 0, i64 %tmp_11
  %valIn_data_V_load_1 = load i32* %valIn_data_V_addr_3, align 4
  %tmp_6 = icmp slt i32 %valIn_data_V_load, %valIn_data_V_load_1
  br i1 %tmp_6, label %2, label %._crit_edge41.0

; <label>:2                                       ; preds = %1
  store i32 %valIn_data_V_load_1, i32* %valIn_data_V_addr_2, align 4
  store i32 %valIn_data_V_load, i32* %valIn_data_V_addr_3, align 4
  br label %._crit_edge41.0

.preheader33.preheader.0:                         ; preds = %.preheader36.0
  %empty_8 = call i32 (...)* @_ssdm_op_SpecLoopTripCount(i64 5000, i64 5000, i64 5000)
  %tmp_2 = call i32 (...)* @_ssdm_op_SpecRegionBegin([12 x i8]* @p_str3)
  br label %.preheader33.0

.loopexit.loopexit1.1:                            ; preds = %.preheader34.1
  %empty_9 = call i32 (...)* @_ssdm_op_SpecRegionEnd([12 x i8]* @p_str3, i32 %tmp_7)
  %stage_1 = add i14 %stage1, 2
  br label %.preheader36.0

.preheader34.1:                                   ; preds = %._crit_edge.1, %.loopexit.loopexit.0
  %i_s = phi i14 [ %i_3_1, %._crit_edge.1 ], [ 2, %.loopexit.loopexit.0 ]
  %tmp_9_1 = icmp ult i14 %i_s, -6384
  br i1 %tmp_9_1, label %3, label %.loopexit.loopexit1.1

._crit_edge.1:                                    ; preds = %4, %3
  %empty_10 = call i32 (...)* @_ssdm_op_SpecRegionEnd([5 x i8]* @p_str4, i32 %tmp_9)
  %i_3_1 = add i14 %i_s, 2
  br label %.preheader34.1

; <label>:3                                       ; preds = %.preheader34.1
  %empty_11 = call i32 (...)* @_ssdm_op_SpecLoopTripCount(i64 4999, i64 4999, i64 4999)
  call void (...)* @_ssdm_op_SpecLoopName([5 x i8]* @p_str4) nounwind
  %tmp_9 = call i32 (...)* @_ssdm_op_SpecRegionBegin([5 x i8]* @p_str4)
  call void (...)* @_ssdm_op_SpecPipeline(i32 1, i32 1, i32 1, i32 0, [1 x i8]* @p_str1) nounwind
  %tmp_7_1 = zext i14 %i_s to i64
  %tmp_10_1 = add i14 %i_s, -1
  %tmp_11_1 = zext i14 %tmp_10_1 to i64
  %valIn_data_V_addr_4 = getelementptr [10000 x i32]* %valIn_data_V, i64 0, i64 %tmp_7_1
  %valIn_data_V_load_2 = load i32* %valIn_data_V_addr_4, align 8
  %valIn_data_V_addr_5 = getelementptr [10000 x i32]* %valIn_data_V, i64 0, i64 %tmp_11_1
  %valIn_data_V_load_3 = load i32* %valIn_data_V_addr_5, align 4
  %tmp_12_1 = icmp slt i32 %valIn_data_V_load_2, %valIn_data_V_load_3
  br i1 %tmp_12_1, label %4, label %._crit_edge.1

; <label>:4                                       ; preds = %3
  store i32 %valIn_data_V_load_3, i32* %valIn_data_V_addr_4, align 8
  store i32 %valIn_data_V_load_2, i32* %valIn_data_V_addr_5, align 4
  br label %._crit_edge.1

.preheader:                                       ; preds = %.preheader36.0, %5
  %idx2 = phi i14 [ %idx_2, %5 ], [ 0, %.preheader36.0 ]
  %exitcond = icmp eq i14 %idx2, -6384
  %idx_2 = add i14 %idx2, 1
  br i1 %exitcond, label %6, label %5

; <label>:5                                       ; preds = %.preheader
  %empty_12 = call i32 (...)* @_ssdm_op_SpecLoopTripCount(i64 10000, i64 10000, i64 10000)
  %tmp_3 = call i32 (...)* @_ssdm_op_SpecRegionBegin([12 x i8]* @p_str6)
  call void (...)* @_ssdm_op_SpecPipeline(i32 1, i32 1, i32 1, i32 0, [1 x i8]* @p_str1) nounwind
  %tmp_5 = zext i14 %idx2 to i64
  %valIn_data_V_addr_1 = getelementptr [10000 x i32]* %valIn_data_V, i64 0, i64 %tmp_5
  %tmp_data_V_1 = load i32* %valIn_data_V_addr_1, align 4
  %valIn_keep_V_addr_1 = getelementptr [10000 x i4]* %valIn_keep_V, i64 0, i64 %tmp_5
  %tmp_keep_V_1 = load i4* %valIn_keep_V_addr_1, align 4
  %valIn_strb_V_addr_1 = getelementptr [10000 x i4]* %valIn_strb_V, i64 0, i64 %tmp_5
  %tmp_strb_V_1 = load i4* %valIn_strb_V_addr_1, align 1
  %valIn_user_V_addr_1 = getelementptr [10000 x i2]* %valIn_user_V, i64 0, i64 %tmp_5
  %tmp_user_V_1 = load i2* %valIn_user_V_addr_1, align 2
  %valIn_last_V_addr_1 = getelementptr [10000 x i1]* %valIn_last_V, i64 0, i64 %tmp_5
  %tmp_last_V_1 = load i1* %valIn_last_V_addr_1, align 1
  %valIn_id_V_addr_1 = getelementptr [10000 x i5]* %valIn_id_V, i64 0, i64 %tmp_5
  %tmp_id_V_1 = load i5* %valIn_id_V_addr_1, align 4
  %valIn_dest_V_addr_1 = getelementptr [10000 x i6]* %valIn_dest_V, i64 0, i64 %tmp_5
  %tmp_dest_V_1 = load i6* %valIn_dest_V_addr_1, align 1
  call void @_ssdm_op_Write.axis.volatile.i32P.i4P.i4P.i2P.i1P.i5P.i6P(i32* %outStream_V_data_V, i4* %outStream_V_keep_V, i4* %outStream_V_strb_V, i2* %outStream_V_user_V, i1* %outStream_V_last_V, i5* %outStream_V_id_V, i6* %outStream_V_dest_V, i32 %tmp_data_V_1, i4 %tmp_keep_V_1, i4 %tmp_strb_V_1, i2 %tmp_user_V_1, i1 %tmp_last_V_1, i5 %tmp_id_V_1, i6 %tmp_dest_V_1)
  %empty_13 = call i32 (...)* @_ssdm_op_SpecRegionEnd([12 x i8]* @p_str6, i32 %tmp_3)
  br label %.preheader

; <label>:6                                       ; preds = %.preheader
  ret void
}

define weak void @_ssdm_op_Write.axis.volatile.i32P.i4P.i4P.i2P.i1P.i5P.i6P(i32*, i4*, i4*, i2*, i1*, i5*, i6*, i32, i4, i4, i2, i1, i5, i6) {
entry:
  store i32 %7, i32* %0
  store i4 %8, i4* %1
  store i4 %9, i4* %2
  store i2 %10, i2* %3
  store i1 %11, i1* %4
  store i5 %12, i5* %5
  store i6 %13, i6* %6
  ret void
}

define weak void @_ssdm_op_SpecTopModule(...) {
entry:
  ret void
}

define weak i32 @_ssdm_op_SpecRegionEnd(...) {
entry:
  ret i32 0
}

define weak i32 @_ssdm_op_SpecRegionBegin(...) {
entry:
  ret i32 0
}

define weak void @_ssdm_op_SpecPipeline(...) nounwind {
entry:
  ret void
}

define weak i32 @_ssdm_op_SpecLoopTripCount(...) {
entry:
  ret i32 0
}

define weak void @_ssdm_op_SpecLoopName(...) nounwind {
entry:
  ret void
}

define weak void @_ssdm_op_SpecInterface(...) nounwind {
entry:
  ret void
}

define weak void @_ssdm_op_SpecBitsMap(...) {
entry:
  ret void
}

define weak { i32, i4, i4, i2, i1, i5, i6 } @_ssdm_op_Read.axis.volatile.i32P.i4P.i4P.i2P.i1P.i5P.i6P(i32*, i4*, i4*, i2*, i1*, i5*, i6*) {
entry:
  %empty = load i32* %0
  %empty_14 = load i4* %1
  %empty_15 = load i4* %2
  %empty_16 = load i2* %3
  %empty_17 = load i1* %4
  %empty_18 = load i5* %5
  %empty_19 = load i6* %6
  %mrv_0 = insertvalue { i32, i4, i4, i2, i1, i5, i6 } undef, i32 %empty, 0
  %mrv1 = insertvalue { i32, i4, i4, i2, i1, i5, i6 } %mrv_0, i4 %empty_14, 1
  %mrv2 = insertvalue { i32, i4, i4, i2, i1, i5, i6 } %mrv1, i4 %empty_15, 2
  %mrv3 = insertvalue { i32, i4, i4, i2, i1, i5, i6 } %mrv2, i2 %empty_16, 3
  %mrv4 = insertvalue { i32, i4, i4, i2, i1, i5, i6 } %mrv3, i1 %empty_17, 4
  %mrv5 = insertvalue { i32, i4, i4, i2, i1, i5, i6 } %mrv4, i5 %empty_18, 5
  %mrv6 = insertvalue { i32, i4, i4, i2, i1, i5, i6 } %mrv5, i6 %empty_19, 6
  ret { i32, i4, i4, i2, i1, i5, i6 } %mrv6
}

declare i16 @_ssdm_op_HSub(...)

declare i16 @_ssdm_op_HMul(...)

declare i16 @_ssdm_op_HDiv(...)

declare i16 @_ssdm_op_HAdd(...)

declare void @_GLOBAL__I_a() nounwind section ".text.startup"

!hls.encrypted.func = !{}
!llvm.map.gv = !{!0}

!0 = metadata !{metadata !1, [1 x i32]* @llvm_global_ctors_0}
!1 = metadata !{metadata !2}
!2 = metadata !{i32 0, i32 31, metadata !3}
!3 = metadata !{metadata !4}
!4 = metadata !{metadata !"llvm.global_ctors.0", metadata !5, metadata !"", i32 0, i32 31}
!5 = metadata !{metadata !6}
!6 = metadata !{i32 0, i32 0, i32 1}
!7 = metadata !{metadata !8}
!8 = metadata !{i32 0, i32 31, metadata !9}
!9 = metadata !{metadata !10}
!10 = metadata !{metadata !"inStream.V.data.V", metadata !5, metadata !"int32", i32 0, i32 31}
!11 = metadata !{metadata !12}
!12 = metadata !{i32 0, i32 3, metadata !13}
!13 = metadata !{metadata !14}
!14 = metadata !{metadata !"inStream.V.keep.V", metadata !5, metadata !"uint4", i32 0, i32 3}
!15 = metadata !{metadata !16}
!16 = metadata !{i32 0, i32 3, metadata !17}
!17 = metadata !{metadata !18}
!18 = metadata !{metadata !"inStream.V.strb.V", metadata !5, metadata !"uint4", i32 0, i32 3}
!19 = metadata !{metadata !20}
!20 = metadata !{i32 0, i32 1, metadata !21}
!21 = metadata !{metadata !22}
!22 = metadata !{metadata !"inStream.V.user.V", metadata !5, metadata !"uint2", i32 0, i32 1}
!23 = metadata !{metadata !24}
!24 = metadata !{i32 0, i32 0, metadata !25}
!25 = metadata !{metadata !26}
!26 = metadata !{metadata !"inStream.V.last.V", metadata !5, metadata !"uint1", i32 0, i32 0}
!27 = metadata !{metadata !28}
!28 = metadata !{i32 0, i32 4, metadata !29}
!29 = metadata !{metadata !30}
!30 = metadata !{metadata !"inStream.V.id.V", metadata !5, metadata !"uint5", i32 0, i32 4}
!31 = metadata !{metadata !32}
!32 = metadata !{i32 0, i32 5, metadata !33}
!33 = metadata !{metadata !34}
!34 = metadata !{metadata !"inStream.V.dest.V", metadata !5, metadata !"uint6", i32 0, i32 5}
!35 = metadata !{metadata !36}
!36 = metadata !{i32 0, i32 31, metadata !37}
!37 = metadata !{metadata !38}
!38 = metadata !{metadata !"outStream.V.data.V", metadata !5, metadata !"int32", i32 0, i32 31}
!39 = metadata !{metadata !40}
!40 = metadata !{i32 0, i32 3, metadata !41}
!41 = metadata !{metadata !42}
!42 = metadata !{metadata !"outStream.V.keep.V", metadata !5, metadata !"uint4", i32 0, i32 3}
!43 = metadata !{metadata !44}
!44 = metadata !{i32 0, i32 3, metadata !45}
!45 = metadata !{metadata !46}
!46 = metadata !{metadata !"outStream.V.strb.V", metadata !5, metadata !"uint4", i32 0, i32 3}
!47 = metadata !{metadata !48}
!48 = metadata !{i32 0, i32 1, metadata !49}
!49 = metadata !{metadata !50}
!50 = metadata !{metadata !"outStream.V.user.V", metadata !5, metadata !"uint2", i32 0, i32 1}
!51 = metadata !{metadata !52}
!52 = metadata !{i32 0, i32 0, metadata !53}
!53 = metadata !{metadata !54}
!54 = metadata !{metadata !"outStream.V.last.V", metadata !5, metadata !"uint1", i32 0, i32 0}
!55 = metadata !{metadata !56}
!56 = metadata !{i32 0, i32 4, metadata !57}
!57 = metadata !{metadata !58}
!58 = metadata !{metadata !"outStream.V.id.V", metadata !5, metadata !"uint5", i32 0, i32 4}
!59 = metadata !{metadata !60}
!60 = metadata !{i32 0, i32 5, metadata !61}
!61 = metadata !{metadata !62}
!62 = metadata !{metadata !"outStream.V.dest.V", metadata !5, metadata !"uint6", i32 0, i32 5}
