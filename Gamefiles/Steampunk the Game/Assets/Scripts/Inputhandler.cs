using System;
using System.Collections;
using System.Collections.Generic;
using System.Runtime.CompilerServices;
using UnityEngine;

public class Inputhandler : MonoBehaviour
{

    public float master;
    public float music;
    public float SFX;

    private void Awake()
    {
        DontDestroyOnLoad(gameObject);
    }
}
