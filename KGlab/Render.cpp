#include "Render.h"
#include <Windows.h>
#include <GL\GL.h>
#include <GL\GLU.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "GUItextRectangle.h"
#include <random>


#define PI 3.14159265358979323846


struct point
{
	double x = 0;
	double y = 0;
	double z = 0;

	const double* p() const
	{
		return &x;
	}
};

void static cyl(int seed = 0)
{
	glBegin(GL_QUADS);
	double A[] = { 1.0, 0.0, 0.0 };
	double B[] = { 6.0, 3.0, 0.0 };
	double C[] = { 4.0, 7.0, 0.0 };
	double D[] = { 0.0, 2.0, 0.0 };
	double E[] = { -4.0, 3.0, 0.0 };
	double F[] = { -7.0, -2.0, 0.0 };
	double G[] = { -2.0, -6.0, 0.0 };
	double H[] = { 3.0, -4.0, 0.0 };
	double height = 1.0;
	double A1[] = { 1.0, 0.0,height };
	double B1[] = { 6.0, 3.0, height };
	double C1[] = { 4.0, 7.0, height };
	double D1[] = { 0.0, 2.0, height };
	double E1[] = { -4.0, 3.0, height };
	double F1[] = { -7.0, -2.0, height };
	double G1[] = { -2.0, -6.0, height };
	double H1[] = { 3.0, -4.0, height };

	std::mt19937 gen(seed);
	std::uniform_real_distribution<double> r(0, 1);
	//floor

	glNormal3d(0, 0, -1);
	glColor3d(r(gen), r(gen), r(gen));
	glVertex3dv(A);
	glVertex3dv(B);
	glVertex3dv(C);
	glVertex3dv(D);

	glNormal3d(0, 0, -1);
	glColor3d(r(gen), r(gen), r(gen));
	glVertex3dv(A);
	glVertex3dv(D);
	glVertex3dv(E);
	glVertex3dv(H);

	glNormal3d(0, 0, -1);
	glColor3d(r(gen), r(gen), r(gen));
	glVertex3dv(E);
	glVertex3dv(F);
	glVertex3dv(G);
	glVertex3dv(H);

	//roof
	glNormal3d(0, 0, 1);
	glColor3d(r(gen), r(gen), r(gen));
	glVertex3dv(A1);
	glVertex3dv(B1);
	glVertex3dv(C1);
	glVertex3dv(D1);

	glNormal3d(0, 0, 1);
	glColor3d(r(gen), r(gen), r(gen));
	glVertex3dv(A1);
	glVertex3dv(D1);
	glVertex3dv(E1);
	glVertex3dv(H1);

	//walls connecting

	
	glColor3d(r(gen), r(gen), r(gen));
	glVertex3dv(A);
	glVertex3dv(A1);
	glVertex3dv(B1);
	glVertex3dv(B);

	glColor3d(r(gen), r(gen), r(gen));
	glVertex3dv(B);
	glVertex3dv(B1);
	glVertex3dv(C1);
	glVertex3dv(C);

	glColor3d(r(gen), r(gen), r(gen));
	glVertex3dv(C);
	glVertex3dv(C1);
	glVertex3dv(D1);
	glVertex3dv(D);

	glColor3d(r(gen), r(gen), r(gen));
	glVertex3dv(D);
	glVertex3dv(D1);
	glVertex3dv(E1);
	glVertex3dv(E);

	glColor3d(r(gen), r(gen), r(gen));
	glVertex3dv(F);
	glVertex3dv(F1);
	glVertex3dv(G1);
	glVertex3dv(G);

	glColor3d(r(gen), r(gen), r(gen));
	glVertex3dv(E1);
	glVertex3dv(F1);
	glVertex3dv(G1);
	glVertex3dv(H1);

	glColor3d(r(gen), r(gen), r(gen));
	glVertex3dv(G);
	glVertex3dv(G1);
	glVertex3dv(H1);
	glVertex3dv(H);

	glColor3d(r(gen), r(gen), r(gen));
	glVertex3dv(H);
	glVertex3dv(H1);
	glVertex3dv(A1);
	glVertex3dv(A);

	double VectorFE[] = { F[0] - E[0], F[1] - E[1], F[2] - E[2] };
	double startfaza = atan(VectorFE[1] / VectorFE[0]);
	double MID[] = { (E[0] + F[0]) / 2,(E[1] + F[1]) / 2, (E[2] + F[2]) / 2 };
	double radius = sqrt(VectorFE[0] * VectorFE[0] + VectorFE[1] * VectorFE[1]) / 2; //sqrt(13)
	int i = 0;
	glColor3d(r(gen), r(gen), r(gen));
	// выпуклость на грани e f f1 e1
	while (i < 90)
	{
		double x = MID[0] + radius * (cos(2 * PI * i / 180 + startfaza));
		double y = MID[1] + radius * (sin(2 * PI * i / 180 + startfaza));
		double z = MID[2];
		double x1 = MID[0] + radius * (cos(2 * PI * (i + 1) / 180 + startfaza));
		double y1 = MID[1] + radius * (sin(2 * PI * (i + 1) / 180 + startfaza));
		double z1 = MID[2];
		glColor3d(r(gen), r(gen), r(gen));
		glVertex3d(MID[0], MID[1], MID[2]); // центр
		glVertex3d(x, y, z); //начало
		glVertex3d(x1, y1, z1);  // прирощение
		glVertex3d(MID[0], MID[1], MID[2]);
		glColor3d(r(gen), r(gen), r(gen));
		glVertex3d(x, y, z);
		glVertex3d(x, y, z + height);
		glVertex3d(x1, y1, z1 + height);
		glVertex3d(x1, y1, z1);
		glColor3d(r(gen), r(gen), r(gen));
		glVertex3d(MID[0], MID[1], MID[2] + height); // центр
		glVertex3d(x, y, z + height); //начало
		glVertex3d(x1, y1, z1 + height);  // прирощение
		glVertex3d(MID[0], MID[1], MID[2] + height);
		i++;
	}
	glEnd();
}


#ifdef _DEBUG
#include <Debugapi.h> 
struct debug_print
{
	template<class C>
	debug_print& operator<<(const C& a)
	{
		OutputDebugStringA((std::stringstream() << a).str().c_str());
		return *this;
	}
} debout;
#else
struct debug_print
{
	template<class C>
	debug_print& operator<<(const C& a)
	{
		return *this;
	}
} debout;
#endif

//библиотека для разгрузки изображений
//https://github.com/nothings/stb
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

//внутренняя логика "движка"
#include "MyOGL.h"
extern OpenGL gl;
#include "Light.h"
Light light;
#include "Camera.h"
Camera camera;


bool texturing = true;
bool lightning = true;
bool alpha = false;


//переключение режимов освещения, текстурирования, альфаналожения
void switchModes(OpenGL *sender, KeyEventArg arg)
{
	//конвертируем код клавиши в букву
	auto key = LOWORD(MapVirtualKeyA(arg.key, MAPVK_VK_TO_CHAR));

	switch (key)
	{
	case 'L':
		lightning = !lightning;
		break;
	case 'T':
		texturing = !texturing;
		break;
	case 'A':
		alpha = !alpha;
		break;
	}
}

//Текстовый прямоугольничек в верхнем правом углу.
//OGL не предоставляет возможности для хранения текста
//внутри этого класса создается картинка с текстом (через виндовый GDI),
//в виде текстуры накладывается на прямоугольник и рисуется на экране.
//Это самый простой способ что то написать на экране
//но ооооочень не оптимальный
GuiTextRectangle text;

//айдишник для текстуры
GLuint texId;
//выполняется один раз перед первым рендером
void initRender()
{
	//==============НАСТРОЙКА ТЕКСТУР================
	//4 байта на хранение пикселя
	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);

	//просим сгенерировать нам Id для текстуры
	//и положить его в texId
	glGenTextures(1, &texId);

	//делаем текущую текстуру активной
	//все, что ниже будет применено texId текстуре.
	glBindTexture(GL_TEXTURE_2D, texId);


	int x, y, n;

	//загружаем картинку
	//см. #include "stb_image.h" 
	unsigned char* data = stbi_load("texture.png", &x, &y, &n, 4);
	//x - ширина изображения
	//y - высота изображения
	//n - количество каналов
	//4 - нужное нам количество каналов
	//пиксели будут хранится в памяти [R-G-B-A]-[R-G-B-A]-[..... 
	// по 4 байта на пиксель - по байту на канал
	//пустые каналы будут равны 255

	//Картинка хранится в памяти перевернутой 
	//так как ее начало в левом верхнем углу
	//по этому мы ее переворачиваем -
	//меняем первую строку с последней,
	//вторую с предпоследней, и.т.д.
	unsigned char* _tmp = new unsigned char[x * 4]; //времянка
	for (int i = 0; i < y / 2; ++i)
	{
		std::memcpy(_tmp, data + i * x * 4, x * 4);//переносим строку i в времянку
		std::memcpy(data + i * x * 4, data + (y - 1 - i) * x * 4, x * 4); //(y-1-i)я строка -> iя строка
		std::memcpy(data + (y - 1 - i) * x * 4, _tmp, x * 4); //времянка -> (y-1-i)я строка
	}
	delete[] _tmp;


	//загрузка изображения в видеопамять
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, x, y, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

	//выгрузка изображения из опперативной памяти
	stbi_image_free(data);


	//настройка режима наложения текстур
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
												  //GL_REPLACE -- полная замена политога текстурой
	//настройка тайлинга
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	//настройка фильтрации
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//======================================================

	//================НАСТРОЙКА КАМЕРЫ======================
	camera.caclulateCameraPos();

	//привязываем камеру к событиям "движка"
	gl.WheelEvent.reaction(&camera, &Camera::Zoom);
	gl.MouseMovieEvent.reaction(&camera, &Camera::MouseMovie);
	gl.MouseLeaveEvent.reaction(&camera, &Camera::MouseLeave);
	gl.MouseLdownEvent.reaction(&camera, &Camera::MouseStartDrag);
	gl.MouseLupEvent.reaction(&camera, &Camera::MouseStopDrag);
	//==============НАСТРОЙКА СВЕТА===========================
	//привязываем свет к событиям "движка"
	gl.MouseMovieEvent.reaction(&light, &Light::MoveLight);
	gl.KeyDownEvent.reaction(&light, &Light::StartDrug);
	gl.KeyUpEvent.reaction(&light, &Light::StopDrug);
	//========================================================
	//====================Прочее==============================
	gl.KeyDownEvent.reaction(switchModes);
	text.setSize(512, 180);
	//========================================================
	   

	camera.setPosition(2, 1.5, 1.5);
}

void Render(double delta_time)
{    
	glEnable(GL_DEPTH_TEST);
	
	//натройка камеры и света
	//в этих функциях находятся OGLные функции
	//которые устанавливают параметры источника света
	//и моделвью матрицу, связанные с камерой.

	if (gl.isKeyPressed('F')) //если нажата F - свет из камеры
	{
		light.SetPosition(camera.x(), camera.y(), camera.z());
	}
	camera.SetUpCamera();
	light.SetUpLight();


	//рисуем оси
	gl.DrawAxes();

	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	

	//включаем режимы, в зависимости от нажания клавиш. см void switchModes(OpenGL *sender, KeyEventArg arg)
	if (lightning)
		glEnable(GL_LIGHTING);
	if (texturing)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 0); //сбрасываем текущую текстуру
	}
		
	if (alpha)
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}
		
	//=============НАСТРОЙКА МАТЕРИАЛА==============


	//настройка материала, все что рисуется ниже будет иметь этот метериал.
	//массивы с настройками материала
	float  amb[] = { 0.2, 0.2, 0.1, 1. };
	float dif[] = { 0.4, 0.65, 0.5, 1. };
	float spec[] = { 0.9, 0.8, 0.3, 1. };
	float sh = 0.2f * 256;

	//фоновая
	glMaterialfv(GL_FRONT, GL_AMBIENT, amb);
	//дифузная
	glMaterialfv(GL_FRONT, GL_DIFFUSE, dif);
	//зеркальная
	glMaterialfv(GL_FRONT, GL_SPECULAR, spec); 
	//размер блика
	glMaterialf(GL_FRONT, GL_SHININESS, sh);

	//чтоб было красиво, без квадратиков (сглаживание освещения)
	glShadeModel(GL_SMOOTH); //закраска по Гуро      
			   //(GL_SMOOTH - плоская закраска)

	//============ РИСОВАТЬ ТУТ ==============
	cyl();
	

	////квадратик станкина
	////так как расчет освещения происходит только в вершинах
	//// (закраска по Гуро)
	////то рисуем квадратик из более маленьких квадратиков
	//glBindTexture(GL_TEXTURE_2D, texId);
	//glBegin(GL_QUADS);
	//glNormal3d(0, 0, 1);
	//double h = 0.025;
	//for (double x = h; x<= 1; x+= h)
	//	for (double y = h; y <= 1; y += h)
	//	{
	//		glColor3d(1, 1, 0);

	//		glTexCoord2d(x, y);
	//		glVertex2d(x, y);

	//		glTexCoord2d(x-h, y);
	//		glVertex2d(x-h, y);

	//		glTexCoord2d(x - h, y-h);
	//		glVertex2d(x - h, y-h);

	//		glTexCoord2d(x, y - h);
	//		glVertex2d(x, y - h);
	//	}
	//glEnd();


	//===============================================

	//рисуем источник света
	light.DrawLightGizmo();

	//================Сообщение в верхнем левом углу=======================

	//переключаемся на матрицу проекции
	glMatrixMode(GL_PROJECTION);
	//сохраняем текущую матрицу проекции с перспективным преобразованием
	glPushMatrix();
	//загружаем единичную матрицу в матрицу проекции
	glLoadIdentity();

	//устанавливаем матрицу паралельной проекции
	glOrtho(0, gl.getWidth() - 1, 0, gl.getHeight() - 1, 0, 1);

	//переключаемся на моделвью матрицу
	glMatrixMode(GL_MODELVIEW);
	//сохраняем матрицу
	glPushMatrix();
    //сбразываем все трансформации и настройки камеры загрузкой единичной матрицы
	glLoadIdentity();

	//отрисованное тут будет визуалзироватся в 2д системе координат
	//нижний левый угол окна - точка (0,0)
	//верхний правый угол (ширина_окна - 1, высота_окна - 1)

	
	std::wstringstream ss;
	ss << std::fixed << std::setprecision(3);
	ss << "T - " << (texturing ? L"[вкл]выкл  " : L" вкл[выкл] ") << L"текстур" << std::endl;
	ss << "L - " << (lightning ? L"[вкл]выкл  " : L" вкл[выкл] ") << L"освещение" << std::endl;
	ss << "A - " << (alpha ? L"[вкл]выкл  " : L" вкл[выкл] ") << L"альфа-наложение" << std::endl;
	ss << L"F - Свет из камеры" << std::endl;
	ss << L"G - двигать свет по горизонтали" << std::endl;
	ss << L"G+ЛКМ двигать свет по вертекали" << std::endl;
	ss << L"Коорд. света: (" << std::setw(7) <<  light.x() << "," << std::setw(7) << light.y() << "," << std::setw(7) << light.z() << ")" << std::endl;
	ss << L"Коорд. камеры: (" << std::setw(7) << camera.x() << "," << std::setw(7) << camera.y() << "," << std::setw(7) << camera.z() << ")" << std::endl;
	ss << L"Параметры камеры: R=" << std::setw(7) << camera.distance() << ",fi1=" << std::setw(7) << camera.fi1() << ",fi2=" << std::setw(7) << camera.fi2() << std::endl;
	ss << L"delta_time: " << std::setprecision(5)<< delta_time << std::endl;

	
	text.setPosition(10, gl.getHeight() - 10 - 180);
	text.setText(ss.str().c_str());
	text.Draw();

	//восстанавливаем матрицу проекции на перспективу, которую сохраняли ранее.
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	

}   



