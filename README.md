# Xếp lịch học (Qt Desktop)

Ứng dụng desktop Qt 6 để đọc dữ liệu môn học và khung giờ từ file text, sau đó xếp lịch bằng tô màu đồ thị tham lam.

## Chuẩn bị

Cần có:

- CMake 3.24 trở lên;
- trình biên dịch C++20 (Visual Studio Build Tools trên Windows);
- Qt 6.4 trở lên với module **Widgets**.

Khi Qt không nằm trong đường dẫn mặc định của CMake, cung cấp đường dẫn cài Qt bằng `CMAKE_PREFIX_PATH`:

```powershell
cmake -S . -B cmake-build -DCMAKE_PREFIX_PATH="C:\Qt\6.x.x\msvc2022_64"
cmake --build cmake-build --config Debug
```

## Dữ liệu đầu vào

Đặt hai file sau trong `backend/data/` rồi build lại:

`Course.txt` gồm mỗi môn trên một dòng, theo dạng:

```text
Tên môn,số tiết mỗi tuần
OOP,7
DiscreteMath,9
```

`TimeSlot.txt` có dòng đầu là số khung giờ (chỉ để mô tả), các dòng sau theo dạng:

```text
Thứ,số tiết,giờ bắt đầu,giờ kết thúc
MON,1,07:30,08:15
MON,2,08:15,09:00
```

## Chạy

Sau khi build, mở:

```powershell
.\cmake-build\backend\Debug\OptimalSchedule.exe
```

CMake chép dữ liệu vào thư mục `data` cạnh file `.exe`, nên có thể chạy bằng cách nhấp đúp vào file đó. Khi chỉnh sửa dữ liệu trong `backend/data`, build lại để cập nhật bản sao cạnh `.exe`.

Trong cửa sổ ứng dụng, bấm **Tải dữ liệu và xếp lịch** để đọc lại file và tạo bảng lịch. Mỗi môn hiện được coi là xung đột với các môn khác, nên thuật toán phân chúng vào các khung giờ riêng.
