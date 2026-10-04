// Function: sub_AA657C
// RVA: 0xaa657c, Size: 732 bytes
int64_t sub_AA657C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glViewport(...); // call PLT API at 0xaa65a0
    glDisable(...); // call PLT API at 0xaa65a8
    glEnable(...); // call PLT API at 0xaa65b0
    glBlendFuncSeparate(...); // call PLT API at 0xaa65c4
    glEnable(...); // call PLT API at 0xaa65cc
    glCullFace(...); // call PLT API at 0xaa65d4
    glUseProgram(...); // call PLT API at 0xaa65dc
    const char* str = "mvpMatrix";
    glGetUniformLocation(...); // call PLT API at 0xaa65ec
    glUniformMatrix4fv(...); // call PLT API at 0xaa65fc
    const char* str = "u_alpha";
    glGetUniformLocation(...); // call PLT API at 0xaa660c
    glUniform1f(...); // call PLT API at 0xaa6614
    const char* str = "a_position";
    glGetAttribLocation(...); // call PLT API at 0xaa6624
    const char* str = "a_normal";
    glGetAttribLocation(...); // call PLT API at 0xaa663c
    const char* str = "a_color";
    glGetAttribLocation(...); // call PLT API at 0xaa6654
    glBindBuffer(...); // call PLT API at 0xaa6678
    glVertexAttribPointer(...); // call PLT API at 0xaa6694
    glEnableVertexAttribArray(...); // call PLT API at 0xaa669c
    glVertexAttribPointer(...); // call PLT API at 0xaa66b8
    glEnableVertexAttribArray(...); // call PLT API at 0xaa66c0
    glVertexAttribPointer(...); // call PLT API at 0xaa66dc
    glEnableVertexAttribArray(...); // call PLT API at 0xaa66e4
    glBindBuffer(...); // call PLT API at 0xaa66f8
    glDrawElements(...); // call PLT API at 0xaa6710
    glBindBuffer(...); // call PLT API at 0xaa6740
    glBufferData(...); // call PLT API at 0xaa6754
    glVertexAttribPointer(...); // call PLT API at 0xaa6770
    glEnableVertexAttribArray(...); // call PLT API at 0xaa6778
    glVertexAttribPointer(...); // call PLT API at 0xaa6794
    glEnableVertexAttribArray(...); // call PLT API at 0xaa679c
    glVertexAttribPointer(...); // call PLT API at 0xaa67b8
    glEnableVertexAttribArray(...); // call PLT API at 0xaa67c0
    glBindBuffer(...); // call PLT API at 0xaa67cc
    glBufferData(...); // call PLT API at 0xaa67e0
    glDrawElements(...); // call PLT API at 0xaa67fc
    glDisableVertexAttribArray(...); // call PLT API at 0xaa6804
    glDisableVertexAttribArray(...); // call PLT API at 0xaa680c
    glDisableVertexAttribArray(...); // call PLT API at 0xaa6814
    glBindBuffer(...); // call PLT API at 0xaa6820
    glBindBuffer(...); // call PLT API at 0xaa682c
    glDisable(...); // call PLT API at 0xaa6834
    glDisable(...); // call PLT API at 0xaa683c
    glDisable(...); // call PLT API at 0xaa6854
}
