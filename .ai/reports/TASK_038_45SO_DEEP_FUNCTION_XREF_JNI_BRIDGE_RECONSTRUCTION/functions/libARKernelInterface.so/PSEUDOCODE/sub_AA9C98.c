// Function: sub_AA9C98
// RVA: 0xaa9c98, Size: 436 bytes
int64_t sub_AA9C98(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glViewport(...); // call PLT API at 0xaa9cb8
    glUseProgram(...); // call PLT API at 0xaa9cc0
    const char* str = "u_mvpMatrix";
    glGetUniformLocation(...); // call PLT API at 0xaa9cd0
    glUniformMatrix4fv(...); // call PLT API at 0xaa9ce0
    glActiveTexture(...); // call PLT API at 0xaa9ce8
    glBindTexture(...); // call PLT API at 0xaa9cf4
    const char* str = "u_texture";
    glGetUniformLocation(...); // call PLT API at 0xaa9d04
    glUniform1i(...); // call PLT API at 0xaa9d0c
    glBindVertexArray(...); // call PLT API at 0xaa9d28
    glDrawElements(...); // call PLT API at 0xaa9d3c
    glBindVertexArray(...); // call PLT API at 0xaa9d98
    glDrawElements(...); // call PLT API at 0xaa9db4
    glBindVertexArray(...); // call PLT API at 0xaa9e20
    glDrawElements(...); // call PLT API at 0xaa9e34
    glBindVertexArray(...); // call PLT API at 0xaa9e48
}
