/*
 * =====================================================================================
 *
 *       Filename:  Window.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  19/09/2014 19:51:04
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#define GLM_FORCE_RADIANS
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Debug.hpp"
#include "OpenGL.hpp"
#include "Window.hpp"

Window::Window() {
	m_isOpen = false;
}

Window::~Window() {
}

void Window::open() {
#ifdef __ANDROID__
	SDL_DisplayMode current;
	SDL_GetCurrentDisplayMode(0, &current);
	
	info("Current display: %dx%d", current.w, current.h);
	
	m_width = current.w;
	m_height = current.h;
#else
	m_width = WINDOW_WIDTH * 3;
	m_height = WINDOW_HEIGHT * 3;
#endif
	
	m_window = SDL_CreateWindow(APP_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_width, m_height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
	if(!m_window) {
		error("Error while initializing window: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	
	m_context = SDL_GL_CreateContext(m_window);
	
	m_defaultShader.load("shaders/default.v.glsl", "shaders/default.f.glsl");
	useDefaultShader();
	
	glEnableVertexAttribArray(m_defaultShader.attrib("coord2d"));
	glEnableVertexAttribArray(m_defaultShader.attrib("texcoord"));
	
	initGL();
	
	m_isOpen = true;
}

void Window::free() {
	SDL_GL_DeleteContext(m_context);
	SDL_DestroyWindow(m_window);
}

void Window::initGL() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	glEnable(GL_TEXTURE_2D);
	
	glm::mat4 projectionMatrix = glm::ortho(0.0f, (float)WINDOW_WIDTH, (float)WINDOW_HEIGHT, 0.0f);
	
	glUniformMatrix4fv(m_defaultShader.uniform("uProjectionMatrix"), 1, GL_FALSE, glm::value_ptr(projectionMatrix));
}

void Window::clear() {
	glClear(GL_COLOR_BUFFER_BIT);
}

void Window::update() {
	SDL_GL_SwapWindow(m_window);
}

void Window::useDefaultShader() {
	m_defaultShader.useProgram();
}
