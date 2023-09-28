using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class lineCode : MonoBehaviour
{
    LineRenderer lineRenderer;

    public Transform origin;
    public Transform destination;


    private void Start()
    {
        lineRenderer = GetComponent<LineRenderer>();
        lineRenderer.startWidth = 0.1f;
        lineRenderer.endWidth = 0.1f;
    }

    private void Update()
    {
        lineRenderer.SetPosition(0, origin.position);
        lineRenderer.SetPosition(1, destination.position);
    }
}