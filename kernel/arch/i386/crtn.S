.section .init
    /* gcc will put contents of crtend.o's .init section here */
    popl %ebp
    ret

.section .fini
    /* gcc will put contents of crtend.o's .fini section here */
    popl %ebp
    ret

