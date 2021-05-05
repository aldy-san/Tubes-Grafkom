#include <gl/glut.h>
#include <stdlib.h>
#include <Math.h>
#define PI 3.14159265f
void rgb(float red, float green, float blue){
	red = red/255;
	green = green/255;
	blue = blue/255;
	glColor3f(red, green, blue);
}
struct Pallette {
    void merah() {
        rgb(255, 0, 0);
    }
    void biru(){
    	rgb(39, 60, 117);
	}
    void hijau() {
        rgb(39, 174, 96);
    }
    void hijauTua() {
        rgb(0, 150, 0);
    }
    void hijauMuda() {
        rgb(110,200,150);
    }
    void hijau2(){
    	rgb(122,214,112);
	}
    void kuning(){
    	rgb(241, 196, 15);
	}
	void kuningCerah(){
    	rgb(241, 241, 15);
	}
    void putih() {
        rgb(255, 255, 255);
    }
    void abuabu(){
    	rgb(149, 165, 166);
	}
	void abuabuTua(){
    	rgb(127, 140, 141);
	}
	void hampirPutih (){
    	rgb(245, 245, 245);
	}
	void biruLaut(){
		rgb(145,216,232);
	}
	void biruLautTua(){
		rgb(1,76,118);
	}
	void langit(){
		rgb(255,234,219);
	}
	void coklat(){
		rgb(139,106,103);
	}
	void cokelat2(){
        rgb(231, 168, 65);
	}
	void cokelat3(){
        rgb(255, 215, 149);
	}
};

Pallette painter;
void segitiga(float angle,float l, float t, float posX, float posY) {
	l = l/2;
	glPushMatrix();
	glTranslatef(posX, posY, 0.0f);
	glRotatef(angle, 0.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLES);
    glVertex2f(-l, 0.);
    glVertex2f(l, 0.);
    glVertex2f(0., t);
    glEnd();
    glPopMatrix();
}

void segitigaSiku(float angle,float l, float t, float posX, float posY, int hadap) {
	l = l/2;
	glPushMatrix();
	glTranslatef(posX, posY, 0.0f);
	glRotatef(angle, 0.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLES);
    glVertex2f(-l, 0.);
    glVertex2f(l, 0.);
    if(hadap == 0){
    	//KIRI
    	glVertex2f(l, t);
	} else {
		//KANAN
		glVertex2f(-l, t);
	}
    glEnd();
    glPopMatrix();
}

void persegi(float angle,float p, float l, float posX, float posY) {
	glPushMatrix();
	glTranslatef(posX, posY, 0.0f);
	glRotatef(angle, 0.0f, 0.0f, 1.0f);
	glBegin(GL_QUADS);
    glVertex2f(p, l);
    glVertex2f(-p, l);
    glVertex2f(-p, -l);
    glVertex2f(p,-l);
    glEnd();
    glPopMatrix();
}

void lingkaran(float ballRadius, float posX, float posY){
	glPushMatrix();
	glTranslatef(posX, posY, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(0.0f, 0.0f);
	int numSegments = 100;
	GLfloat angle;
	for(int i = 0; i <= numSegments; i++){
		angle = i * 2.0f * PI / numSegments;
		glVertex2f(cos(angle) * ballRadius, sin(angle) * ballRadius);
	}
	glEnd();
	glPopMatrix();
}

void awan(float scale, float posX, float posY){
	painter.putih();
	glPushMatrix();
	glScalef(scale, scale, 1.0);
	glTranslatef(posX, posY, 0.0);
	lingkaran(20, 0.0, 0.0);
	lingkaran(20, 20.0, 10.0);
	lingkaran(30, 40.0, 20.0);
	lingkaran(20, 30.0, 0.0);
	glEnd();
	glPopMatrix();
}

void awan2(float scale, float posX, float posY){
	painter.putih();
	glPushMatrix();
	glScalef(scale, scale, 1.0);
	glTranslatef(posX, posY, 0.0);
	lingkaran(20, 10.0, 10.0);
	lingkaran(20, -5.0, 10.0);
	lingkaran(25, 20.0, 10.0);
	lingkaran(20, 45.0, 10.0);
	glEnd();
	glPopMatrix();
}

void gunung(float scale, float posX, float posY){
	glPushMatrix();
	glScalef(scale, scale, 1.0);
	glTranslatef(posX, posY, 0.0);
	painter.abuabu();
    segitiga(0, 200, 300, 0.0, 0.0);
    painter.hampirPutih();
    segitiga(0, 70, 100, 0.0, 200.0);
    painter.hampirPutih();
    segitiga(180, 20, 40, 20.0, 200.0);
    painter.abuabu();
    segitiga(0, 15, 20, -20.0, 200.0);
	glEnd();
	glPopMatrix();
}

void pohon(float scale, float posX, float posY){
	glPushMatrix();
	glScalef(scale, scale, 1.0);
	glTranslatef(posX, posY, 0.0);
	painter.coklat();
	persegi(0, 10, 30, 0.0, 0.0);
	painter.hijauTua();
	segitiga(0, 50, 100, 0., 10);
	glEnd();
	glPopMatrix();
}

void kincirAngin(float scale, float posX, float posY){
	glPushMatrix();
	glScalef(scale, scale, 1.0);
	glTranslatef(posX, posY, 0.0);
	painter.putih();
	persegi(0, 12, 100, 0.0, 0.0);
	painter.abuabu();
	lingkaran(25, 0.0, 120);
	painter.putih();
	segitiga(0, 30, 120, 0.0, 120);
	segitiga(120, 30, 120, 0.0, 120);
	segitiga(-120, 30, 120, 0.0, 120);
	glEnd();
	glPopMatrix();
}

void pohon2(float posX, float posY, float scale){
    glPushMatrix();
    glTranslatef(posX, posY, 0.0);
    glScalef(scale, scale, 0.0);

    //batang
    painter.cokelat2();
    persegi(0, 0.5, 1.25, 0, 0);

    //daun
    painter.hijau();
    segitiga(0, 5, 3, 0, 0);
    segitiga(0, 5, 3, 0, 1);
    segitiga(0, 5, 3, 0, 2);

    glPopMatrix();
}

void rumah(float posX, float posY, float scale){
    glPushMatrix();
    glTranslatef(posX, posY, 0.0);
    glScalef(scale, scale, 0.0);

    //cerobong asap
    painter.biru();
    persegi(0, 3, 5, 0, 43);

    //tembok depan
    painter.putih();
    segitiga(0, 30, 20, -26, 20);
    persegi(0, 13, 10, -26, 10);

    //tembok samping
    painter.hampirPutih();
    persegi(0, 19, 10, 6, 10);

    //atap
    painter.cokelat3();
    segitigaSiku(180, 20, 20, -20, 40, 1);
    persegi(0, 10, 10, 0, 30);
    persegi(53, 12, 1.5, -35, 30);
    segitigaSiku(0, 20, 20, 20, 20, 1);

    glEnd();
    glPopMatrix();
}

void kapal(float scale, float posX, float posY){
	glPushMatrix();
	glScalef(scale, scale, 1.0);
	glTranslatef(posX, posY, 0.0);
	//ATAS kapal
	painter.abuabu();
	persegi(0, 100, 50, 200, 100);
	segitigaSiku(0, 100, 100, 50.0, 50, 0);
	persegi(0, 15, 40, 220, 180);
		//JENDELA
		painter.putih();
		persegi(0, 20, 20, 160, 110);
		persegi(0, 20, 20, 230, 110);
	//BADAN kapal
	painter.abuabuTua();
	persegi(0, 250, 60, 0.0, 0.0);
	segitigaSiku(90, 120, 120, -250, 0.0,0);
	segitigaSiku(-90, 120, 120, 250, 0.0,1);
	painter.biru();
	persegi(0, 250, 10, 0.0, -70);
	painter.putih();
	persegi(0, 50, 12, -195, -40);
	segitigaSiku(90, 24, 24, -245, -40,0);
	glEnd();
	glPopMatrix();
}

void gradasiAir(){
	glPushMatrix();
	glTranslatef(0, -240, 0.0f);
	glRotatef(0, 0.0f, 0.0f, 1.0f);
	glBegin(GL_QUADS);
    painter.biruLautTua();
    glVertex2f(900, 110);
    glVertex2f(-900, 110);
	painter.biruLaut();
    glVertex2f(-900, -110);
    glVertex2f(900,-110);
    glEnd();
    glPopMatrix();
}

void initGL(){
	glClearColor(255/255., 234/255., 210/255., 1.0);
}

void render(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    //MATAHARI
    painter.kuningCerah();
    lingkaran(55, -275, 200);
    painter.kuning();
    lingkaran(40, -275, 200);
    //GUNUNG
    gunung(0.9, -320., -130.);
    gunung(1.3, -150., -100.);
    gunung(1., -50., -100.);
    gunung(0.8, 50., -130.);
    gunung(0.9, 130., -70.);
    gunung(1.5, 160., -70.);

    //BUKIT
	painter.hijauMuda();
    lingkaran(300, 225, -200);
    painter.hijau();
    lingkaran(250, -200, -200);
    painter.hijau2();
    lingkaran(130, 90, -170);

	    //POHON
	    pohon(0.4, 200.0, -300.0);
	    pohon(0.6, 200.0, -190.0);
	    pohon(0.4, 600.0, -300.0);
	    pohon(0.4, -950.0, -300.0);
	    pohon(0.6, -580.0, -190.0);
	    pohon(0.4, -700.0, -300.0);
	    pohon(0.4, -450.0, -300.0);
	    pohon(0.4, -300.0, -300.0);
	    pohon(0.6, 370, -190.0);
	    pohon(0.5, 850, -240.0);

	    //KINCIR ANGIN
	    kincirAngin(0.85, 350.0, -80.0);
	    kincirAngin(0.50, 720.0, -200.0);
	    kincirAngin(0.50, 720.0, -200.0);

    //LAUT
    gradasiAir();
    	//KAPAL
    	kapal(0.5, 280.0, -500.0);

    //Tembok
    rumah(20, 20, 2);
    pohon2(100, 150, 20);
    //AWAN dari kiri->kanan
    awan(1.25, -220.0, 120.0);
    awan2(1., -100.0, 285.0);
    awan(0.8, 90.0, 225.0);
    awan2(1.5, 180.0, 160.0);
    glFlush();


}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(900, 700);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Pemandangan");
    gluOrtho2D(-450., 450., -350., 350.);
    glutDisplayFunc(render);
    initGL();
    glutMainLoop();

    return EXIT_SUCCESS;
}

