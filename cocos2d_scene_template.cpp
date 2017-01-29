#include "%FILE_NAME.h"

USING_NS_CC;

%SCENE_NAME* %SCENE_NAME::createScene()
{
	%SCENE_NAME* new%SCENE_NAME = %SCENE_NAME::create();
	return new%SCENE_NAME;
}

bool %SCENE_NAME::init()
{
	if (!cocos2d::Scene::init())
	{
		return false;
	}

	// Uncomment this to activate update(float) function
	//this->scheduleUpdate();

	return true;
}

void %SCENE_NAME::onEnter()
{
	cocos2d::Scene::onEnter();
	// Uncomment this to enable mouse and keyboard event listeners
	//initInputListeners();
}

void %SCENE_NAME::update(float delta)
{

}

void %SCENE_NAME::initInputListeners()
{
	this->mouseInputListener = EventListenerMouse::create();
	this->mouseInputListener->onMouseMove = CC_CALLBACK_1(%SCENE_NAME::onMouseMove, this);
	this->mouseInputListener->onMouseDown = CC_CALLBACK_1(%SCENE_NAME::onMouseDown, this);
	this->mouseInputListener->onMouseUp = CC_CALLBACK_1(%SCENE_NAME::onMouseUp, this);
	this->mouseInputListener->onMouseScroll = CC_CALLBACK_1(%SCENE_NAME::onMouseScroll, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(this->mouseInputListener, this);

	this->keyInputListener = EventListenerKeyboard::create();
	this->keyInputListener->onKeyPressed = CC_CALLBACK_2(%SCENE_NAME::onKeyPressed, this);
	this->keyInputListener->onKeyReleased = CC_CALLBACK_2(%SCENE_NAME::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(this->keyInputListener, this);
}

void %SCENE_NAME::onMouseMove(cocos2d::Event* event) 
{
	//auto mouseEvent = static_cast<EventMouse*>(event);
	//float x = mouseEvent->getCursorX();
	//float y = mouseEvent->getCursorY();
}

void %SCENE_NAME::onMouseDown(cocos2d::Event* event) 
{
	//auto mouseEvent = static_cast<EventMouse*>(event);
	//0 = left, 1 = right, 2 = middle
	//int mouseButton = mouseEvent->getMouseButton();
	//float x = mouseEvent->getCursorX();
	//float y = mouseEvent->getCursorY();
}

void %SCENE_NAME::onMouseUp(cocos2d::Event* event) 
{
	//auto mouseEvent = static_cast<EventMouse*>(event);
	//0 = left, 1 = right, 2 = middle
	//int mouseButton = mouseEvent->getMouseButton();
	//float x = mouseEvent->getCursorX();
	//float y = mouseEvent->getCursorY();
}

void %SCENE_NAME::onMouseScroll(cocos2d::Event* event) 
{
	//auto mouseEvent = static_cast<EventMouse*>(event);
	//float x = mouseEvent->getScrollX();
	//float y = mouseEvent->getScrollY();
}

void %SCENE_NAME::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) 
{

}

void %SCENE_NAME::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) 
{

}

void %SCENE_NAME::releaseInputListeners()
{
	if(this->mouseInputListener != nullptr)
		_eventDispatcher->removeEventListener(this->mouseInputListener);
	if(this->keyInputListener != nullptr)
		_eventDispatcher->removeEventListener(this->keyInputListener);
}

void %SCENE_NAME::onExit()
{
	cocos2d::Scene::onExit();
	// Uncomment this if you are using initInputListeners()
	//releaseInputListeners(); 
}