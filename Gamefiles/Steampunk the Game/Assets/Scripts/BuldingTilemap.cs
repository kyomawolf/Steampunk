using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using UnityEngine;
using UnityEngine.Tilemaps;
using UnityEngine.UIElements;

public class BuldingTilemap : MonoBehaviour
{
    public bool isBuildingMode;
    public Tilemap buildingTilemap;
    public int buildCount;
    public List<BuildingList> allBuildings;
    public List<Tile> testBuildings = new List<Tile>();
    public Camera curCam;


    private void Awake()
    {
        //buildCount = allBuildings.Count - 1;
    }

    void Start()
    {
        isBuildingMode = true;
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKey(KeyCode.Mouse0) && isBuildingMode)
        {
            Build();
        }
    }


    private void Build()
    {
        Vector3 pos = Input.mousePosition;
        Vector3 world = curCam.ScreenToWorldPoint(pos);
        Vector3Int cell = buildingTilemap.WorldToCell(world);
        cell.z = 0;
        //buildingTilemap.SetTile(cell, allBuildings[buildCount].Tile);
        buildingTilemap.SetTile(cell, testBuildings[0]);
    }
}
