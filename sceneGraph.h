#ifndef __SCENEGRAPH_H__	//guard against cyclic dependancy
#define __SCENEGRAPH_H__

//Header file for the SceneGraph

#include "node.h"
#include "nodeModel.h"
#include "Math/math3D.h"
#include "Math/Hitbox.h"
#include <vector>

class SceneGraph{
public:
	SceneGraph();	//constructor

	//Scene Graph Navigation
	void goToRoot();
	void goToChild(int i);
	void goToParent();
	void insertChildNodeHere(Node *node);
	void deleteThisNode();
	void searchByID(int ID);
	bool Intersect(int x, int y);

	//Scene Graph Draw
	void draw();
	void transformNode(Node *node);
	void deleteScene();
	void clearScene(Node *n);

	// Variables for Intersect
	vec3D near,far,distance;
	double matModelView[16], matProjection[16]; 
	int viewport[4]; 
	double* start;
	double* finish;
	Node *currentNode;
	vector<Node*> hitBoxNodes;

private:
	
	Node *rootNode;
};

#endif