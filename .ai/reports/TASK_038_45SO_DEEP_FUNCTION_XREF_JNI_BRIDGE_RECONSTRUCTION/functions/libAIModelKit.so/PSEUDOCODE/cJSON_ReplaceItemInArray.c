// Function: cJSON_ReplaceItemInArray
// RVA: 0x1d418, Size: 84 bytes
int64_t cJSON_ReplaceItemInArray(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    cJSON_Delete(...); // call imported API via PLT at 0x1d464
    return a0;
}
