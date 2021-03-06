
#include "BaseLayer.h"
USING_NS_CC;
class PlayScene :public BaseLayer{
public:
	PlayScene();
	~PlayScene();
	bool init();
	static cocos2d::Scene* createScene();
	CREATE_FUNC(PlayScene);
	void initPositionPoints(float offX);//Initialize the monster path set
	void addMonster();
	void logic(float t);
	void firstLogic(float t);//first start waiting to do something 
	void update(float t);

private:
	TMXTiledMap* map;
	TMXLayer* bgLayer;
	TMXObjectGroup* objects;
	Vector<Node*> positionPointsVector;
	float offX;
	Label* time;
	float currTime = 6;
};