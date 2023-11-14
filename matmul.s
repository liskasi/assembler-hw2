.global matmul

matmul:
  ldr r1, [sp, #52]  // Load mat2
  ldr r2, [sp, #56]  // Load mat2 (address of the second matrix)
  ldr r3, [sp, #12] // Load rslt (address of the result matrix)
  ldr r4, [sp, #16] // Load R1 (number of rows for the first matrix)
  ldr r5, [sp, #20] // Load C1 (number of columns for the first matrix)
  ldr r6, [sp, #24] // Load R2 (number of rows for the second matrix)
  ldr r7, [sp, #28] // Load C2 (number of columns for the second matrix)
  mov r8, #0
  outer_loop:
    cmp r8, r4
    bge outer_loop_end

    mov r9, #0

    middle_loop:
      cmp r9, r7
      bge middle_loop_end

      mov r10, #0
      mov r11, #0

      inner_loop:
        cmp r10, r6
        bge inner_loop_end

        mov r0, r1
        add r12, r0, r10, LSL #2
        mov r0, r1
        add r13, r0, r8, LSL #2

        // mov r12, #0

        //mov r0, r2
        //add r13, r0, r10, LSL #2
        //add r14, r2, r10, LSL #2

        //mul r12, r13, r14
        //add r10, r10, r12
        ldr r3, [r13]

        add r10, r10, #1
        b inner_loop

      inner_loop_end:
      add r9, r9, #1
      b middle_loop
    middle_loop_end:
    add r8, r8, #1
    b outer_loop

  outer_loop_end:
  mov r0, r3
  bx lr
  .end
