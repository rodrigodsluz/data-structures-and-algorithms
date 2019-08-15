using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour{
	public int life;
	public bool isFlying;
	public string name;
	
	public float velocity;
	public float distance;
	public float time;
	
	public float maximumVelocity;
	public float minimumVelocity;
	
    // Start is called before the first frame update
    void Start(){
        //checksVelocity();
    }

    // Update is called once per frame
    void Update(){
		if(Input.GetKeyDown(KeyCode.Space)){
			checksVelocity();
		}
    }
	
	void checksVelocity(){
		velocity = distance/time;
		Debug.Log("Your velocity is: "+ velocity);
		if(velocity < minimumVelocity){
			Debug.Log("You are so slow!");
		}else if(velocity > maximumVelocity){
			Debug.Log("You are so fast!");
		}else{
			Debug.Log("Congratulations! You are in the correct velocity!");
		}
	}
}
