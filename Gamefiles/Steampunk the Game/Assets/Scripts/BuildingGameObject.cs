using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BuildingGameObject
{
    public int team;            //for an allysystem
    public int ID;              //what building exactly is this??
    public int maxHP;           //maximum amount of HP
    public int currentHP;       //current amount of HP
    public int distance;        //distance from HQ needed for determination if a trainconnection is needed
    public bool connected;      //if building is connected to a trainstation or the HQ
    public int neededWorkers;   //if and how many workers are needed to run this building
    public int currentWorkers;  //are there currently workers in the building
    public bool functional;     //does it currently work?
    public float resistance;    //factors incoming damage; lower than 1 for higher resistance and higher than 1 for "negative" resistance
    public Vector3Int size;     //size of the building
    public Vector3Int spawn;    //point where a unit will spawn
}
