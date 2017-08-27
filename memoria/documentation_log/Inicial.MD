# Investigación inicial
A continuación se dejarán las notas respecto a
## Plataforma Objetivo
Los algoritmos serán desarrollados en un SoC Xilinx Zynq 7000 Series, los cuales son SoC híbridos que cuentan con un procesador ARM v7 2@1.0GHz y una FPGA categoría SPARTAN con 300.000 compuertas lógicas y 42 slices DSP disponibles.

### FPGA
Field Programable Grid Array, un arreglo de compuertas lógicas y slices DSP (Digital Signal Processor) los cuales es posible programar por medio de lenguajes de descripción de hardware como VHDL, Verilog o SystemC.

Comunmente utilizadas en electrónica de potencia como switches de alta frequencia debido a que combinan la flexibilidad de la lógica programable junto con la velocidad de connmutación de los circuitos electrónicos combinacionales.

### Comparación frente a CPU
Las FPGA para conmutar estado en las compuertas lógicas utilizan un reloj el cual marca la frecuencia de cambio. Este reloj no puede ser muy rápido ni muy lento, dado que si si frecuencia es baja, se pierde poder de procesamiento y si es muy rápido podrían haber interferencias en el circuito debido a energía residual.

En el caso de la Zynq 7000, el reloj es utilizado comunmente a 100MHz y 150MHz. Esto en comparación al procesador principal que maneja 1GHz parece ser bastante lento, sin embargo la diferencia es visible al momento de considerar el paralelismo de los problemas.

Por ejemplo, en el caso de obtención de medianas aproximadas por medio de BFPRT, este subordena grupos de 5 elementos en un arreglo y recursivamente elige el elemento central. Para cada uno de estos elementos se vuelve a repetir el proceso.

Este proceso tiene un tiempo de cálculo aproximado de 58N. Sin embargo, en el caso de una FPGA, es posible hacer uso de mallas de ordenamiento, las cuales utilizan circuetería combinacional para ordenar estos 5 elementos en un único ciclo de reloj. Está claro que ordernar 50 elementos debe ser igual o más rapido que ordenar estos 50 elementos en la CPU.

### Sintetización de circuitos
Para programar las compuertas de una FPGA se utilizan herramientas sinterizadoras, las cuales permiten convertir códigos de descripción de lenguaje a una malla de compuertas lógicas, las cuales son entregadas a la FPGA.

Antes de eso, la descripción de lenguaje objetivo pasa por un proceso de "sintetización", el cual es el equivalente al proceso de "compilación" comunmente llamado en software. Durante el proceso de sinterización se optimizan rutas, etc, etc.

## Arquitectura propuesta
### DMA
### AMBA
### AXI4
## Pruebas iniciales