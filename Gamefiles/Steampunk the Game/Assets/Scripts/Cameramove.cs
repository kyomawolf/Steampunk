using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Cameramove : MonoBehaviour
{
    public float mainSpeed = 90.0f; //regular speed
    private float totalRun= 1.0f;
    public Camera Cam;
    public int camTransform;
    private void Start()
    {
        Cam.orthographicSize = 5;

        camTransform = Tilemapground.fieldSize;
        Vector3 pe = new Vector3(0, (float) (camTransform * 0.25), 0);
        transform.Translate(pe);
    }

    void Update () {
        //Keyboard commands
        Vector3 p = GetBaseInput();
        
            totalRun = Mathf.Clamp(totalRun * 0.5f, 1f, 1000f);
            p = p * mainSpeed;

            p = p * Time.deltaTime;
            transform.Translate(p);
            if (Input.GetAxis("Mouse ScrollWheel") < 0)
            {
                switch(Cam.orthographicSize)
                {
                    case 5:
                        Cam.orthographicSize = 8;
                        break;
                    case 8:
                        Cam.orthographicSize = 13;
                        break;
                    default:
                        break;
                }
            } 
            if (Input.GetAxis("Mouse ScrollWheel") > 0)
            {
                switch(Cam.orthographicSize)
                {
                    case 13:
                        Cam.orthographicSize = 8;
                        break;
                    case 8:
                        Cam.orthographicSize = 5;
                        break;
                    default:
                        break;
                }
            }

    }
     
    private Vector3 GetBaseInput() { //returns the basic values, if it's 0 than it's not active.
        Vector3 p_Velocity = new Vector3();
        if (Input.GetKey (KeyCode.W)){
            p_Velocity += new Vector3(0, 1 , 0);
        }
        if (Input.GetKey (KeyCode.S)){
            p_Velocity += new Vector3(0, -1, 0);
        }
        if (Input.GetKey (KeyCode.A)){
            p_Velocity += new Vector3(-1, 0, 0);
        }
        if (Input.GetKey (KeyCode.D)){
            p_Velocity += new Vector3(1, 0, 0);
        }
        return p_Velocity;
    }
}
