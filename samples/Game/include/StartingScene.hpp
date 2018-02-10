#ifndef __STARTINGSCENE__HPP
#define __STARTINGSCENE__HPP

#include "simpleGL.hpp"
#include "memory"


class StartingScene: public simpleGL::IScene
{
private:
    simpleGL::Node*         m_pFirstNode;
    simpleGL::NodeManager*  m_pContainer;

    simpleGL::Triangle*     m_pTriangles[2];
    simpleGL::Quad*         m_pQuad;

    simpleGL::Shader        m_colorShader;
    simpleGL::Shader        m_uvShader;

    simpleGL::Texture       m_textureWall;
    simpleGL::Texture       m_textureContainer;
    simpleGL::Texture       m_textureSmile;

    // To enable texture zoom
    float m_zoomScale = 1.0f;

    void ChangeGreenOverTime(simpleGL::Shader& _shader);
    void ZoomUVOverTime(simpleGL::Shader& _shader);
    void ZoomUV(simpleGL::Shader& _shader, bool _zoom);

public:
    StartingScene();
    virtual ~StartingScene();

    virtual bool OnInit();
    virtual bool OnUpdate();
    virtual bool OnQuit();
    virtual void OnRender();

    // @TODO Must be defined in IScene
    static void MyKeyEventHandler(GLFWwindow* _window, int _key, int _scancode, int _action, int _mods);
};
#endif
