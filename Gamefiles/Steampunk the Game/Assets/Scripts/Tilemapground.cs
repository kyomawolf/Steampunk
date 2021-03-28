using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Tilemaps;
using Random = System.Random;


public class Tilemapground : MonoBehaviour
{
    public List<Tile> grassTest;
    public Tilemap groundTileMap;
    public Tilemap miniMap;
    public int fieldSizeSlider;
    public static int fieldSize;
    private static readonly Random random = new Random(); 
    private static readonly object syncLock = new object(); 
    private void Awake()
    {
        fieldSize = fieldSizeSlider;
        int iii = fieldSize;
        for (int i = 0; i <= fieldSize; i++)
        {
            if (i < fieldSize / 2)
            {
                for (int y = fieldSize / 2 - i; y <= fieldSize / 2 + i; y++)
                {
                    groundTileMap.SetTile(new Vector3Int(i, y, 0), grassTest[GrassGroundHandler()]);
                    miniMap.SetTile(new Vector3Int(i, y, 0), grassTest[0]);
                }
            }
            else
            {
                iii--;
                    for (int ii = iii; ii >= fieldSize - iii; ii--)
                    {
                        groundTileMap.SetTile(new Vector3Int(i, ii, 0), grassTest[GrassGroundHandler()]);
                        miniMap.SetTile(new Vector3Int(i, ii, 0), grassTest[0]);
                    } 
            }
        }
    }


    public int GrassGroundHandler()
    {
        int i;
        lock (syncLock)
        {
            i = random.Next(0, 20);
        }

        if (i <= 18)
        {
            return NumberGenerator(1, 5);
        }
            return NumberGenerator(5, 12);

    }

    public int NumberGenerator(int min, int max)
    {
        lock(syncLock) { // synchronize
            return random.Next(min, max);
        }
    }
    
}
