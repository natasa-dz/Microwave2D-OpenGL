#version 330 core

out vec4 FragColor;

uniform int isGlassOn;

void main() {
    //if(isGlassOn == 1){
        FragColor = vec4(0.5f, 0.7f, 1.0f, 0.5f);
    //}
    //else{
		//FragColor = vec4(0.0f, 0.0f, 0.0f, 0.0f);
	//}
}