

#include "cocos2d.h"
USING_NS_CC;
class BaseSprite : public cocos2d::Sprite{
public:
	BaseSprite();
	~BaseSprite();
	virtual bool init() override;
	CREATE_FUNC(BaseSprite);
	Node* currPosition();//current location
	Node* nextPosition();//The location of the next to go
	void goOnFoot();//walk it out
	void setPositionPoints(Vector<Node*> points);
	static BaseSprite* createSprite(Vector<Node*> points);
private:
	Sprite* sprite;
	Vector<Node*> points;//Want to walk the path of the collection
protected:
	int pointCounter;//Count the steps to go
	CC_SYNTHESIZE(float,speed,speed);//first speed is setSpeed¡¢next is getSpeed
};