# 2022-Logical-Minimization
use the express minimizer to simplify a 6-bit multiplier system, and implement a 4-bit multiplier in the Verilog hardware description language.

# Trabalho Prático 1

```
DCC214 - Introdução aos sistemas lógicos
Igor Joaquim da Silva Costa
```
## 1. Introdução

Os problemas propostos foram: usar o minimizador **espresso** parasimplificarum
sistemademultiplicadorde 6 bits,eimplementarummultiplicadorde 4 bitsnalinguagemde
descriçãodehardwareVerilog.Paraisso,foramusadasferramentasdafaculdadedeBerkeley
e códigos (C/C++) para auxiliar nas tarefas.

## 2. Minimização

Apartedeminimizaçãocorrespondeaoscomandos“makeespresso_input”e“make
espresso_output”contidosnoMakefile.Oprimeirogeraumarquivodetextoquecorresponde
a tabelaverdadedomultiplicadorde 6 bit,usandoaoperaçãodemultiplicaçãodaprópria
linguagem C como base. O segundo processa esse arquivo usando uma instância do espresso.
Ocódigoquegeraaentradaestálocalizadoem“src/multipliyer_input_generator.c”e
as saídas são “entrada_espresso_6bits.txt” e “saida_espresso_6bits.txt”.

## 3. Descrição de hardware -multiplicador de 4 bits

Antesde começaraimplementaçãodocircuito,omesmofoiminimizadousandoo
mesmoprocessoutilizadonaprimeirapartedotrabalho.Apartirdocircuitominimizado,é
possível implementar a função multiplicador comouma soma de produtosparacadabit
presentenaresposta.Assim,foiimplementadoumcódigoemc++quetransformaatabela
verdadegeradanoespressoemsomasdeprodutos,usandoopadrãoestruturalparasimularo
circuito .Aetapa da descrição de hardwarecorresponde ao comando “make verilog”no
Makefile.

```
● Para simularomultiplicadorde 4 bitsemVerilog, foiusadoocompilador Icarus
Verilog 0.9.7;
```

```
● Ocódigofontequetransformaasaídadoespressoemcódigoverilogestálocalizado
em “src/espresso_to_verilog.cpp”;
● O códigofinal em verilog está contido em“design.sv” e a bancada de testeem
“testbench.sv”;
```
## 4. Referências

[1]Código fonte do espresso:https://github.com/classabbyamp/espresso-logic



