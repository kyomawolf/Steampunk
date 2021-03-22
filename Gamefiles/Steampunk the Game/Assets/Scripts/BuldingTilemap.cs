using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using UnityEngine;
using UnityEngine.Tilemaps;

public class BuldingTilemap : MonoBehaviour
{
    public bool isBuildingMode;

    public int buildCount;
    public List<BuildingList> allBuildings;



    private void Awake()
    {
        buildCount = allBuildings.Count - 1;
    }

    void Start()
    {
        isBuildingMode = false;
    }

    // Update is called once per frame
    void Update()
    {
        if (isBuildingMode)
        {
            Build();
        }
    }


    private void Build()
    {
        
    }
}
