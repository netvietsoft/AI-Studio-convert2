uniform mat4 uMVPMatrix;
attribute vec4 aPosition;
attribute vec2 aCameraVetexCoord;
attribute vec2 aTextCoord;
varying vec2 mt_index;
varying vec2 mt_CameraIndex;
void main() {
    mt_index=aTextCoord;
    gl_Position = aPosition;
    mt_CameraIndex=aCameraVetexCoord;
}
