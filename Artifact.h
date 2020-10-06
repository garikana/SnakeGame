#ifndef ARTIFACT_H
#define ARTIFACT_H
#include<SFML/Graphics.hpp>
#include<map>


/*
 * Abstract Artifact class
 * Defines game artifact type and its methods
 *
 */

 class Artifact{

 public:
    Artifact(){}; //default constructor
    virtual bool update(std::map<std::string,Artifact*>& Game_Artifacts, sf::RenderWindow& window,
                        std::vector<sf::Event>& Events)=0; //pure virtual method to update the artifact
    virtual bool draw(sf::RenderWindow& window)=0; //should be virtual to draw the artifact to screen
    virtual std::pair<float,float> get_Position()=0; //should be virtual
    virtual int size()=0; //abstract concept of artifact size

 };
 #endif
