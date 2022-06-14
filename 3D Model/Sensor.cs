using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Sensor : MonoBehaviour
{
    public Animator anim;
    public bool isDisk;
    public bool isWhite = true;

    void Start()
    {
        isDisk = false;
        anim = GameObject.Find("Push off mechanism").GetComponent<Animator>();
    } 

    void OnTriggerEnter(Collider other)
    {
        if(other.gameObject.tag == "Disk")
        {
            isDisk = true; 
            anim.Play("Rotate", 0, 0.0f);
            if(other.gameObject.name.Contains("White"))
            {
                isWhite=true;
            }
            else 
            {
                isWhite=false;
            }
        }
        else
        {
            isDisk = false;
        }
    }
}
