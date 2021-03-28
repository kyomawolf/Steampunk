using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using UnityEditor;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.Tilemaps;
using UnityEngine.UIElements;

public class BuildingTilemap : MonoBehaviour
{
    
    public Tilemap buildingTilemap;
    public static int buildCount;
    public List<BuildingList> allBuildings;
    public List<Tile> testBuildings = new List<Tile>();
    public Camera curCam;


    private void Awake()
    {
        //buildCount = allBuildings.Count - 1;
    }

    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKey(KeyCode.Mouse0) && CanvasScriptGame.isBuildingMode)
        {
            Build();
        }
        if (Input.GetKey(KeyCode.Mouse1))
        {
            CanvasScriptGame.isBuildingMode = false;
        }
    }


    private void Build()
    {
        if (EventSystem.current.IsPointerOverGameObject())
        {
            return;
        }
        Vector3 pos = Input.mousePosition;
        Vector3 world = curCam.ScreenToWorldPoint(pos);
        Vector3Int cell = buildingTilemap.WorldToCell(world);
        cell.z = 0;
        //buildingTilemap.SetTile(cell, allBuildings[buildCount].Tile);
        buildingTilemap.SetTile(cell, testBuildings[buildCount]);
    }
}
