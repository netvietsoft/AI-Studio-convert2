# TIP 01: KHỬ LÀM RỐI R8 / SYNTHETIC & CHUYỂN ĐỔI SANG CLEAN KOTLIN
## DỰ ÁN: MEITU REBORN (CONVERT2)

---

## 1. NHẬN DIỆN VÀ LOẠI BỎ RÁC TRÌNH BIÊN DỊCH (SYNTHETIC ARTIFACTS)

Khi dịch ngược bằng JADX từ APK phát hành, trình tối ưu R8 sinh ra rất nhiều lớp nhân tạo không cần thiết phải convert thủ công:

### Các lớp BẮT BUỘC BỎ QUA (Do trình biên dịch hoặc Annotation Processor tự sinh):
1. **Dagger Factory & Injector:** Các file kết thúc bằng `_Factory.java`, `_MembersInjector.java`, `_Provide*.java`. Khi ta cấu hình Hilt/Dagger trong Gradle, build sẽ tự sinh lại các lớp này.
2. **Synthetic Lambdas:** Các lớp có dạng `*$$ExternalSyntheticLambda*.java`, `*$$ExternalSyntheticThrow*.java`. Hãy chuyển ngược về lambda chuẩn Kotlin: `{ it.id }`.
3. **Coroutine Continuations:** Các lớp có dạng `*$_COROUTINE_*.java` hoặc kế thừa `ContinuationImpl`. Đây là máy trạng thái coroutine; trong Kotlin mới chỉ cần khai báo hàm với từ khóa `suspend`.
4. **SAM Adapters:** Các file chứa `$sam$androidx_lifecycle_Observer$0.java`. Chuyển về lambda: `viewModel.liveData.observe(owner) { data -> ... }`.
5. **ViewBinding & DataBinding Impl:** Các file kết thúc bằng `BindingImpl.java`. Khi bật `buildFeatures { viewBinding = true }`, Android Gradle Plugin sẽ tự tạo.

---

## 2. KHÔI PHỤC THÔNG TIN TỪ `@Metadata`

Khoảng 45% mã nguồn Meitu được viết bằng Kotlin gốc, có chứa chú thích `@Metadata`:
```java
@Metadata(
    d1 = {"..."},
    d2 = {"Lcom/meitu/meitupic/modularembellish/makeup/vm/MakeUpViewModel;", "Landroidx/lifecycle/ViewModel;", "updateBeauty", "isVip"}
)
```
- Trường `d2` chứa tên package và class gốc nếu bị R8 đổi tên ngoài thư mục.
- Các chuỗi trong `d2` chính là tên các hàm và biến nguyên bản trước khi bị obfuscate thành `a`, `b`, `c`. Hãy đối chiếu với `04_kotlin_structure.json` để khôi phục tên hàm có nghĩa.

---

## 3. MẪU CHUYỂN ĐỔI JAVA BOILERPLATE SANG KOTLIN GỌN GÀNG

### Trước (Java dịch ngược cồng kềnh - 40 dòng):
```java
public class FilterModel {
    private String filterId;
    private float intensity;
    private boolean isVip;

    public FilterModel(String filterId, float intensity, boolean isVip) {
        this.filterId = filterId;
        this.intensity = intensity;
        this.isVip = isVip;
    }

    public String getFilterId() { return this.filterId; }
    public void setFilterId(String filterId) { this.filterId = filterId; }
    public float getIntensity() { return this.intensity; }
    public void setIntensity(float intensity) { this.intensity = intensity; }
    public boolean isVip() { return this.isVip; }
    public void setVip(boolean vip) { isVip = vip; }
}
```

### Sau (Kotlin Idiomatic - 5 dòng):
```kotlin
// Source decompiled: jadx_src/sources/com/meitu/edit/filter/FilterModel.java
package com.meitu.edit.filter

data class FilterModel(
    var filterId: String,
    var intensity: Float = 0.8f,
    var isVip: Boolean = false
)
```

---

## 4. CHUYỂN ĐỔI RXJAVA SANG KOTLIN COROUTINES / FLOW

Mã nguồn cũ của Meitu có nhiều đoạn dùng RxJava 2 (`Observable`, `Single`, `CompositeDisposable`). Hãy chuyển đổi sang Kotlin hiện đại:
* `Observable<T>` -> `Flow<T>`
* `Single<T>` -> `suspend fun (): T`
* `Completable` -> `suspend fun ()`
* `CompositeDisposable.add(...)` -> `viewModelScope.launch { ... }`
