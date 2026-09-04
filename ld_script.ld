ENTRY(Start)

MEMORY
{
    EWRAM (rwx) : ORIGIN = 0x2000000, LENGTH = 256K
    IWRAM (rwx) : ORIGIN = 0x3000000, LENGTH = 32K
    ROM    (rx) : ORIGIN = 0x8000000, LENGTH = 32M
}

SECTIONS {


    .ewram ORIGIN(EWRAM) : AT (__ewram_lma)
    ALIGN(4)
    {
        __ewram_start = .;
        *(.ewram*)
        . = ALIGN(4);
        __ewram_end = .;
    } > EWRAM

    .ewram.sbss (NOLOAD) :
    ALIGN(4)
    {
        src/*.o(.sbss);
    } > EWRAM

    /* El monton se queda con TODA la EWRAM que sobre, sea la que sea. Antes era un
       array de tamano fijo, y cada vez que hacia falta mas habia que subir el numero
       a mano mirando cuanto quedaba libre: eso significa que entre subida y subida
       habia memoria pagada y sin usar. Va el ultimo a proposito, para que lo que
       sobre este siempre detras. */
    .ewram.monton (NOLOAD) :
    ALIGN(4)
    {
        __monton_inicio = .;
    } > EWRAM

    __monton_bytes = ORIGIN(EWRAM) + LENGTH(EWRAM) - __monton_inicio;

    /* Si alguien mete tantos datos en EWRAM que el monton se queda en nada, el
       enlazador no protesta -sigue habiendo sitio para los datos-, y el juego se
       cae luego al primer Alloc. Mejor enterarse aqui. */
    /* El suelo NO es un numero redondo: es lo que pide el peor combate. Cuatro pics
       de 96x96 con cinco poses son 92160, el resto del combate 47144 medidos, y las
       animaciones de movimiento unos 16000 encima. Por debajo de eso el juego seguiria
       enlazando y se rompería en la primera batalla doble, que es justo lo que no se
       quiere descubrir jugando. */
    ASSERT(__monton_bytes >= 160K, "No queda EWRAM para el monton: por debajo de 160K los combates dobles con pics grandes se quedan sin memoria. Mira que dato nuevo se ha comido el sitio.")

    .iwram ORIGIN(IWRAM) : AT (__iwram_lma)
    ALIGN(4)
    {
        __iwram_start = .;
        *(.iwram*);
        . = ALIGN(4);
        __iwram_end = .;
    } > IWRAM

    .iwram.bss (NOLOAD) :
    ALIGN(4)
    {
        src/*.o(.bss);
        data/*.o(.bss);
        *libc.a:*.o(.bss*);
        *libnosys.a:*.o(.bss*);

        src/m4a.o(.bss.code);

        src/*.o(common_data);
        src/*.o(COMMON);
        *libc.a:*.o(COMMON);
        *libnosys.a:*.o(COMMON);
    } > IWRAM

    /* BEGIN ROM DATA */

    .text ORIGIN(ROM) :
    ALIGN(4)
    {
        src/rom_header.o(.text*);
        src/crt0.o(.text);
        src/main.o(.text);
        src/*.o(.text*);
        asm/*.o(.text*);
    } > ROM =0

    script_data :
    ALIGN(4)
    {
		data/*.o(script_data);
    } > ROM =0

    lib_text :
    ALIGN(4)
    {
        src/m4a_1.o(.text);
        src/m4a.o(.text);
        src/agb_flash.o(.text);
        src/agb_flash_1m.o(.text);
        src/agb_flash_mx.o(.text);
        *libagbsyscall.a:*.o(.text*);
        *libgcc.a:*.o(.text*);
        *libc.a:*.o(.text*);
        *libnosys.a:*.o(.text*);
    } > ROM =0

    .rodata :
    ALIGN(4)
    {
        src/*.o(.rodata*);
        data/*.o(.rodata*);
    } > ROM =0

    song_data :
    ALIGN(4)
    {
        sound/songs/*.o(.rodata);
    } > ROM =0

    lib_rodata :
    SUBALIGN(4)
    {
        src/m4a.o(.rodata);
        src/agb_flash.o(.rodata);
        src/agb_flash_1m.o(.rodata);
        src/agb_flash_mx.o(.rodata);
        src/agb_flash_le.o(.rodata);
        *libgcc.a:*.o(.rodata*);
        *libc.a:*.o(.rodata*);
        *libc.a:*.o(.data*);
    } > ROM =0

    gfx_data :
    ALIGN(4)
    {
        src/graphics.o(.rodata);
    } > ROM =0

    .data.iwram :
    ALIGN(4)
    {
        __iwram_lma = .;
        . = . + (__iwram_end - __iwram_start);
    } > ROM = 0

    .data.ewram :
    ALIGN(4)
    {
        __ewram_lma = .;
        . = . + (__ewram_end - __ewram_start);
    } > ROM = 0

    __rom_end = .;
}
