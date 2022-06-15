using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Rotate : MonoBehaviour
{

    public Animator animator;
    private bool isDisk;
    // Update is called once per frame
    void Update()
    {
        animator = GetComponent<Animator>();
        isDisk = GameObject.Find("SensorBlockade").GetComponent<Sensor>().isDisk;

        if(isDisk == true)
        {
            animator.SetBool("IsDisk", true);
        }
        else
        {
            animator.SetBool("IsDisk", false);
        }
    }
}
