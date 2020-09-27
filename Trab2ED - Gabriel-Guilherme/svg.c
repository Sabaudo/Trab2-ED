#include"svg.h"
#include"leitura_geo.h"
#include"./elementos/forma.h"
#include"./elementos/texto.h"
#include"./elementos/quadra.h"
#include"./elementos/hidrante.h"
#include"./elementos/semaforo.h"
#include"./elementos/radioBase.h"

//Função que imprimir as formas no arquivo .svg


void svg_imprimir_forma(FILE *arqsvg, Forma forma){
    if(strcmp(getTipoForma(forma), "c")  == 0){
        fprintf(arqsvg, "\n\t<circle\n\t\tid=\"%s\"",getIdForma(forma));
        fprintf(arqsvg, "\n\t\tcx=\"%lf\"", getXForma(forma));
        fprintf(arqsvg, "\n\t\tcy=\"%lf\"", getYForma(forma));
        fprintf(arqsvg, "\n\t\tr=\"%lf\"", getRaioForma(forma));
        fprintf(arqsvg, "\n\t\tstroke=\"%s\"", getcorBordaForma(forma));
        fprintf(arqsvg, "\n\t\tfill=\"%s\"\n\t", getcorPreenchimentoForma(forma));
        fprintf(arqsvg, "\n\tstroke-width=\"%s\"\n\t/>", getSWForma(forma));
    }else{
        fprintf(arqsvg, "\n\t<rect\n\t\tid=\"%s\"",getIdForma(forma));
        fprintf(arqsvg, "\n\t\tx=\"%lf\"",getXForma(forma));
        fprintf(arqsvg, "\n\t\ty=\"%lf\"",getYForma(forma));
        fprintf(arqsvg, "\n\t\twidth=\"%lf\"",getWForma(forma));
        fprintf(arqsvg, "\n\t\theight=\"%lf\"",getHForma(forma));
        fprintf(arqsvg, "\n\t\tstroke=\"%s\"",getcorBordaForma(forma));
        fprintf(arqsvg, "\n\t\tfill=\"%s\"",getcorPreenchimentoForma(forma));
        fprintf(arqsvg, "\n\tstroke-width=\"%s\"\n\t/>", getSWForma(forma));
    }
}  

void svg_imprimir_ponto(FILE *arqsvg, char cor[], double x, double y){
    fprintf(arqsvg, "\n\t<circle\n\t\tid=\"%s\"","2");
    fprintf(arqsvg, "\n\t\tcx=\"%lf\"", x);
    fprintf(arqsvg, "\n\t\tcy=\"%lf\"", y);
    fprintf(arqsvg, "\n\t\tr=\"4\"");
    fprintf(arqsvg, "\n\t\tstroke=\"%s\"", cor);
    fprintf(arqsvg, "\n\t\tfill=\"%s\"\n\t", cor);
    fprintf(arqsvg, "\n\tstroke-width=\"1.0\"\n\t/>");
}

void svg_imprimir_quadra(FILE *arqsvg, Quadra quadra){
    fprintf(arqsvg, "\n\t<rect\n\t\tid=\"%s\"",getCEPQuadra(quadra));
    fprintf(arqsvg, "\n\t\tx=\"%lf\"",getXQuadra(quadra));
    fprintf(arqsvg, "\n\t\ty=\"%lf\"",getYQuadra(quadra));
    fprintf(arqsvg, "\n\t\twidth=\"%lf\"",getWQuadra(quadra));
    fprintf(arqsvg, "\n\t\theight=\"%lf\"",getHQuadra(quadra));
    fprintf(arqsvg, "\n\t\tstroke=\"%s\"",getcorBordaQuadra(quadra));
    fprintf(arqsvg, "\n\t\tfill=\"%s\"",getcorPreenchimentoQuadra(quadra));
    fprintf(arqsvg, "\n\tstroke-width=\"%s\"\n\t/>", getSWQuadra(quadra));
}

void svg_imprimir_hidrante(FILE *arqsvg, Hidrante hidrante){
    fprintf(arqsvg, "\n\t<circle\n\t\tid=\"%s\"",getIDHid(hidrante));
    fprintf(arqsvg, "\n\t\tcx=\"%lf\"", getXHid(hidrante));
    fprintf(arqsvg, "\n\t\tcy=\"%lf\"", getYHid(hidrante));
    fprintf(arqsvg, "\n\t\tr=\"5\"");
    fprintf(arqsvg, "\n\t\tstroke=\"%s\"", getcorBordaHid(hidrante));
    fprintf(arqsvg, "\n\t\tfill=\"%s\"", getcorPreenchimentoHid(hidrante));
    fprintf(arqsvg, "\n\tstroke-width=\"%s\"\n\t/>", getSWHid(hidrante));
}

void svg_imprimir_semaforo(FILE *arqsvg, Semaforo semaforo){
    fprintf(arqsvg, "\n\t<rect\n\t\tid=\"%s\"",getIDSema(semaforo));
    fprintf(arqsvg, "\n\t\tx=\"%lf\"",getXSema(semaforo));
    fprintf(arqsvg, "\n\t\ty=\"%lf\"",getYSema(semaforo));
    fprintf(arqsvg, "\n\t\twidth=\"10\"");
    fprintf(arqsvg, "\n\t\theight=\"10\"");
    fprintf(arqsvg, "\n\t\tstroke=\"%s\"",getcorBordaSema(semaforo));
    fprintf(arqsvg, "\n\t\tfill=\"%s\"",getcorPreenchimentoSema(semaforo));
    fprintf(arqsvg, "\n\tstroke-width=\"%s\"\n\t/>", getSWSema(semaforo));
}

void svg_imprimir_rb(FILE *arqsvg, RadioBase rb){
    fprintf(arqsvg, "\n\t<rect\n\t\tid=\"%s\"",getIDRB(rb));
    fprintf(arqsvg, "\n\t\tx=\"%lf\"",getXRB(rb));
    fprintf(arqsvg, "\n\t\ty=\"%lf\"",getYRB(rb));
    fprintf(arqsvg, "\n\t\twidth=\"5\"");
    fprintf(arqsvg, "\n\t\theight=\"13\"");
    fprintf(arqsvg, "\n\t\tstroke=\"%s\"",getcorBordaRB(rb));
    fprintf(arqsvg, "\n\t\tfill=\"%s\"",getcorPreenchimentoRB(rb));
    fprintf(arqsvg, "\n\tstroke-width=\"%s\"\n\t/>", getSWRB(rb));
}

void svg_imprimir_quadArrend(FILE *arqsvg, Quadra quadra){
    fprintf(arqsvg, "\n\t<rect\n\t\tid=\"%s\"",getCEPQuadra(quadra));
    fprintf(arqsvg, "\n\t\tx=\"%lf\"",getXQuadra(quadra));
    fprintf(arqsvg, "\n\t\ty=\"%lf\"",getYQuadra(quadra));
    fprintf(arqsvg, "\n\t\twidth=\"%lf\"",getWQuadra(quadra));
    fprintf(arqsvg, "\n\t\theight=\"%lf\"",getHQuadra(quadra));
    fprintf(arqsvg, "\n\t\tstroke=\"olive\"");
    fprintf(arqsvg, "\n\t\tfill=\"beige\"");
    fprintf(arqsvg, "\n\t\trx=\"10\"");
    fprintf(arqsvg, "\n\tstroke-width=\"%s\"\n\t/>", getSWQuadra(quadra));
    
}

void anelGrosso(FILE *arqsvg, Elemento e, char tipo[]){
    if (strcmp(tipo, "s") == 0){
        fprintf (arqsvg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"10\" fill=\"none\" stroke=\"blue\" stroke-width=\"6\" />\n", getXSema (e) + 5, getYSema (e) + 5);
        fprintf (arqsvg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"16\" fill=\"none\" stroke=\"green\" stroke-width=\"6\" />\n", getXSema (e) + 5, getYSema (e) + 5);
    }
    else if (strcmp(tipo, "h") == 0){
        fprintf (arqsvg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"10\" fill=\"none\" stroke=\"blue\" stroke-width=\"6\" />\n", getXHid (e), getYHid (e));
        fprintf (arqsvg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"16\" fill=\"none\" stroke=\"green\" stroke-width=\"6\" />\n", getXHid (e), getYHid (e));
    }
    else if (strcmp(tipo, "rb") == 0){
        fprintf (arqsvg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"10\" fill=\"none\" stroke=\"blue\" stroke-width=\"6\" />\n", getXRB (e) + 2.5, getYRB (e) + 6);
        fprintf (arqsvg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"16\" fill=\"none\" stroke=\"green\" stroke-width=\"6\" />\n", getXRB (e) + 2.5, getYRB (e) + 6);
    }
}

//Função que imprimir os textos no arquivo .svg

void svg_imprimirTexto(FILE *arqtxt, Texto texto){
	fprintf(arqtxt, "\n\t<text\n\t\tid=\"%s\"", getIdTexto(texto));
	fprintf(arqtxt, "\n\t\tx=\"%lf\"", getXTexto(texto));
	fprintf(arqtxt, "\n\t\ty=\"%lf\"", getYTexto(texto));
	fprintf(arqtxt, "\n\t\tstroke=\"%s\"", getcorBordaTexto(texto));
	fprintf(arqtxt, "\n\t\tfill=\"%s\">", getcorPreenchimentoTexto(texto));
	fprintf(arqtxt, "\n\t\t%s", getConteudoTexto(texto));
	fprintf(arqtxt, "\n\t</text>\n");
}

//Função que imprimir uma linha no arquivo .svg

void svg_imprimir_linha (FILE *svg, double x1, double y1, double x2, double y2, char cor[]){
    fprintf(svg, "<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\" />\n", x1,y1, x2, y2,cor);
}