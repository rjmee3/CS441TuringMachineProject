    alpha "abAB"

!1
    cmp 'a'
    je !1_a
    cmp 'b'
    je !1_b
    cmp BLANK
    je !1_BLANK
    fail

!1_a
    draw 'A'
    right
    jmp !2

!1_b 
    draw 'B'
    right
    jmp !3

!1_BLANK
    halt

!2
    cmp 'a'
    je !2_a
    cmp 'b'
    je !2_b
    cmp BLANK
    je !2_BLANK
    fail

!2_a 
    right
    jmp !2

!2_b
    draw 'B' 
    right 
    jmp !3

!2_BLANK 
    left
    jmp !4

!3
    cmp 'a'
    je !3_a
    cmp 'b'
    je !3_b
    cmp BLANK 
    je !2_BLANK
    fail

!3_a
    draw 'A'
    right
    jmp !2

!3_b
    right
    jmp !3

!4
    cmp BLANK
    je !4_BLANK
    left
    jmp !4

!4_BLANK
    right
    jmp !5

!5
    cmp 'A'
    or 'B'
    je !5_AB
    cmp 'a'
    or 'b'
    je !5_ab
    cmp BLANK 
    je !5_BLANK
    fail 

!5_AB 
    right 
    jmp !5

!5_ab 
    right
    jmp !6

!5_BLANK 
    left 
    jmp !11

!6
    cmp 'a'
    or 'b'
    je !6_ab
    cmp 'A'
    je !6_A 
    cmp 'B'
    je !6_B 
    cmp BLANK 
    je !6_BLANK
    fail

!6_ab 
    right 
    jmp !6

!6_A 
    draw 'a'
    left
    jmp !7

!6_B 
    draw 'b'
    left 
    jmp !9

!6_BLANK
    left
    jmp !11

!7
    cmp 'A'
    or 'B'
    je !7_AB
    left
    jmp !7

!7_AB
    right
    jmp !8

!8
    draw 'A'
    right
    jmp !6

!9
    cmp 'A'
    or 'B'
    je !9_AB
    left
    jmp !9

!9_AB 
    right 
    jmp !10

!10
    draw 'B'
    right
    jmp !6

!11
    cmp 'a'
    or 'b'
    je !11_ab
    cmp 'A'
    je !11_A 
    cmp 'B'
    je !11_B 
    cmp BLANK 
    je !11_BLANK
    fail

!11_ab 
    draw BLANK
    left
    jmp !11

!11_A 
    draw 'a'
    left 
    jmp !11

!11_B
    draw 'b'
    left 
    jmp !11

!11_BLANK
    right
    halt