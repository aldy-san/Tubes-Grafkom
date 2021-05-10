#include <gl/glut.h>
#include <stdlib.h>
#include <Math.h>
#include <iostream>
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
	void kaca(){
		rgb(165,241,246);
	}
    void hijau() {
        rgb(39, 174, 96);
    }
    void hijau2(){
    	rgb(122,214,112);
	}
	void hijau3(){
		rgb(46, 204, 113);
	}
    void hijauTua() {
        rgb(0, 150, 0);
    }
    void hijauTua2() {
        rgb(16, 172, 132);
    }
    void hijauMuda() {
        rgb(110,200,150);
    }
    void kuning(){
    	rgb(241, 196, 15);
	}
	void kuningCerah(){
    	rgb(241, 241, 15);
	}
	void kuningCerahBanget(){
    	rgb(255, 234, 167);
	}
    void putih() {
        rgb(255, 255, 255);
    }
    void abuabu(){
    	rgb(149, 165, 166);
	}
	void abuabuMuda(){
    	rgb(220, 221, 225);
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
        rgb(139,90,43);
	}
	void cokelat4(){
		rgb(205,133,20);
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

void gunung2(float scale, float posX, float posY){
	glPushMatrix();
	glScalef(scale, scale, 1.0);
	glTranslatef(posX, posY, 0.0);
	painter.abuabuTua();
    segitiga(0, 450, 300, 0.0, 0.0);
    painter.hampirPutih();
    segitiga(0, 150, 100, 0.0, 200.0);
    painter.hampirPutih();
    segitiga(180, 20, 40, 40.0, 200.0);
    painter.abuabuTua();
    segitiga(0, 15, 20, -40.0, 200.0);
	glEnd();
	glPopMatrix();
}

void kincirAngin(float scale, float posX, float posY){
	glPushMatrix();
	glTranslatef(posX, posY, 0.0);
	glScalef(scale, scale, 1.0);
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

void pohon(float scale, float posX, float posY){
	glPushMatrix();
	glTranslatef(posX, posY, 0.0);
	glScalef(scale, scale, 1.0);
	painter.coklat();
	persegi(0, 10, 30, 0.0, 0.0);
	painter.hijau();
	segitiga(0, 59, 109, 0., 10);
	painter.hijauTua();
	segitiga(0, 50, 100, 0., 10);
	glEnd();
	glPopMatrix();
}

void pohon2(float scale, float posX, float posY){
    glPushMatrix();
    glTranslatef(posX, posY, 0.0);
    glScalef(scale, scale, 0.0);

    //batang
    painter.coklat();
    persegi(0, 0.6, 1.55, 0, 0);

    //daun
    painter.hijau();
    segitiga(0, 3.3, 3.3, 0, -0.5);
    segitiga(0, 3.3, 3.3, 0, 0.75);
    segitiga(0, 3.3, 3.3, 0, 2);
    painter.hijauTua();
    segitiga(0, 3, 3, 0, -0.5);
    segitiga(0, 3, 3, 0, 0.75);
    segitiga(0, 3, 3, 0, 2);

    glPopMatrix();
}

void pohon3(float scale, float posX, float posY){
    glPushMatrix();
    glTranslatef(posX, posY, 0.0);
    glScalef(scale, scale, 0.0);

    //daun
    painter.hijauTua();
    segitiga(0, 3, 3, 0, -0.5);
    segitiga(0, 3, 3, 0, 0.75);
    segitiga(0, 3, 3, 0, 2);

    glPopMatrix();
}

void rumah(float scale, float posX, float posY, int hadap, int type){
	
    glPushMatrix();
    glTranslatef(posX, posY, 0.0);
    if(hadap == 0){
    	//KIRI
    	glScalef(scale, scale, 0.0);
	} else {
		//KANAN
		glScalef(-scale, scale, 0.0);
	}
    
    //CEROBONG ASAP
    painter.cokelat2();
    persegi(0, 3, 5, 0, 43);

    //TEMBOK depan
    painter.putih();
    segitiga(0, 30, 20, -26, 20);
    persegi(0, 13, 10, -26, 10);

    //TEMBOK samping
    painter.hampirPutih();
    persegi(0, 19, 10, 6, 10);
	
	//KACA
	painter.cokelat4();
	persegi(0, 5, 5, -2, 12);
	painter.kaca();
	persegi(0, 4, 4, -2, 12);
	
	painter.cokelat4();
	persegi(0, 5, 5, 12, 12);
	painter.kaca();
	persegi(0, 4, 4, 12, 12);
	
    //ATAP
    if(type == 0){
    	painter.cokelat4();
    	persegi(0, 5, 2, -27, 25);
	} else if(type == 1){
		painter.cokelat3();
	}
    segitigaSiku(180, 20, 20, -20, 40, 1);
    persegi(0, 10, 10, 0, 30);
    persegi(53, 12, 1.5, -35, 30);
    segitigaSiku(0, 20, 20, 20, 20, 1);
	
	//PINTU
	persegi(0, 5, 10, -27, 10);
	painter.abuabuMuda();
	lingkaran(2, -25, 10);
    glEnd();
    glPopMatrix();
}

void gereja(float scale, float posX, float posY, int hadap){
    glPushMatrix();
    glTranslatef(posX, posY, 0.0);
    if(hadap == 0){
    	//KIRI
    	glScalef(scale, scale, 0.0);
	} else {
		//KANAN
		glScalef(-scale, scale, 0.0);
	}
    //tembok depan
    painter.putih();
    segitiga(0, 30, 20, -26, 25);
    persegi(0, 13, 13, -26, 13);
	
    //tembok samping
    painter.hampirPutih();
    persegi(0, 26, 13, 13, 13);

    //atap
    painter.cokelat3();
    segitigaSiku(180, 20, 20, -20, 45, 1);
    persegi(0, 16, 10, 6, 35);
    persegi(53, 12, 1.5, -35, 35);
    segitigaSiku(0, 20, 20, 32, 25, 1);
	
	//pintu
	persegi(0, 4, 4, -27.5, 25);
	persegi(0, 5, 8, -27, 8);
	painter.abuabuMuda();
	lingkaran(2, -25, 8);
	//kaca
	painter.cokelat3();
	persegi(0,3.1,8.1,-2,13);
	persegi(0,3.1,8.1,8,13);
	persegi(0,3.1,8.1,18,13);
	persegi(0,3.1,8.1,28,13);
	painter.kaca();
	persegi(0,2.9,8,-2,13);
	persegi(0,2.9,8,8,13);
	persegi(0,2.9,8,18,13);
	persegi(0,2.9,8,28,13);
	
	//salib
	painter.putih();
	persegi(0, 5, 12, -27, 40);
	painter.cokelat3();
    segitiga(0,13,13,-27,49);
    persegi(0, 1, 7, -27, 62);
    persegi(0, 5, 1, -27, 65);
    glEnd();
    glPopMatrix();
}

void initGL(){
	glClearColor(145/255., 216/255., 232/255., 1.0);
}

void render(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    //MATAHARI
    painter.kuningCerahBanget();
    lingkaran(75, -275, 300);
    painter.kuningCerah();
    lingkaran(55, -275, 300);
    painter.kuning();
    lingkaran(40, -275, 300);
	//GUNUNG
	gunung2(1.5, 0., -50.);
	gunung(0.9, -320., -130.);
    gunung(1.3, -150., -100.);
    gunung(1., -50., -100.);
    gunung(0.8, 50., -130.);
    gunung(0.9, 130., -70.);
    gunung(1.5, 160., -70.);
    //DATARAN
    painter.hijauTua2();
    persegi(0, 700, 100, 0, -75);
	    //POHON BELAKANG
		for (int i = 0; i < 100; i++){
			pohon(0.2, i*5, (rand() % 140) - 120);
		}
		for (int i = 0; i < 100; i++){
			pohon(0.2, i*5, (rand() % 140) - 120);
		}
		for (int i = 0; i < 100; i++){
			pohon2(3, i*5, (rand() % 140) - 120);
		}
		for (int i = 0; i < 100; i++){
			pohon(0.2, i*-5, (rand() % 130) - 110);
		}
		for (int i = 0; i < 100; i++){
			pohon(0.2, i*-5, (rand() % 130) - 110);
		}
	//BUKIT
    painter.hijau3();
    lingkaran(600, -320, -600);
    pohon2(10, -30, -180);
    pohon2(9, -70, -180);
    pohon2(12, -50, -190);
	painter.hijau2();
    lingkaran(300, 150, -430);
    pohon2(20, 120, -268);
	pohon2(16, 80, -268);
    painter.hijau();
    lingkaran(500, -180, -680);
    
	    //BANGUNAN
	    pohon(0.4, -200, -180);
		rumah(1.4, -160, -205, 1, 1);
	    pohon(0.6, -188, -200);
		pohon2(9, 10, -290);
		rumah(1.6, -30, -305, 0, 0);
	    pohon2(10, -8, -298);
	    
	    pohon2(12, 215, -120);
		gereja(1.3, 160, -140, 0);
		pohon(0.6, 248, -140);
	    rumah(1.2, 220, -225, 0, 1);
	    pohon(0.5, 250, -220);
	    
		pohon(0.4, -250, -40);
		pohon(0.5, -190, -40);
	    rumah(1.0, -230, -55, 1, 0);
	    rumah(1.1, -80, -125, 0, 1);
    	pohon2(10, -270, -40);
		//KINCIR ANGIN
		kincirAngin(0.9, -260, -285);
		kincirAngin(0.5, -330, -300);
		kincirAngin(0.4, -190, -320);
    //AWAN dari kiri->kanan
    awan(1.25, -220.0, 120.0);
    awan2(1., -100.0, 285.0);
    awan(0.8, 90.0, 225.0);
    awan2(1.5, 180.0, 160.0);

    pohon2(50, 350, -300);
    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Pemandangan");
    gluOrtho2D(-350., 350., -350., 350.);
    glutDisplayFunc(render);
    initGL();
    glutMainLoop();

    return EXIT_SUCCESS;
}

