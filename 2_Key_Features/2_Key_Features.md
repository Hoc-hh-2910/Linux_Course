# Linux_Course

# Bài 1: So sánh Monolithic Kernel và MicroKernel:
1. **Sư khác biệt giữa Monolithic Kernel và Micro Kernel:**
Monolithic Kernel và Micro Kernel là hai kiến trúc hạt nhân (kernel) phổ biến trong hệ điều hành. Dưới đây là những điểm khác biệt chính:
- Cấu trúc:
  Monolithic Kernel: Toàn bộ dịch vụ hệ điều hành (driver, quản lý bộ nhớ, quản lý tiến trình, hệ thống tập tin, v.v.) được tích hợp trong kernel.
  Micro Kernel: Chỉ giữ các chức năng cơ bản nhất như giao tiếp giữa tiến trình (IPC) và quản lý bộ nhớ, còn các dịch vụ khác được đặt trong user space.
- Hiệu suất:
  Monolithic Kernel: Hiệu suất cao hơn do các dịch vụ chạy trong kernel mode, giảm overhead của IPC.
  Micro Kernel: Hiệu suất thấp hơn do phải giao tiếp giữa user space và kernel thông qua IPC, gây thêm độ trễ.
- Độ ổn định:
  Monolithic Kernel: Dễ bị sập hệ thống nếu một thành phần trong kernel gặp lỗi vì mọi thứ chạy trong cùng một không gian.
  Micro Kernel: Ổn định hơn, lỗi ở một dịch vụ không ảnh hưởng đến toàn bộ hệ thống do dịch vụ chạy trong user space.
- Bảo mật:
  Monolithic Kernel: Ổn định hơn, lỗi ở một dịch vụ không ảnh hưởng đến toàn bộ hệ thống do dịch vụ chạy trong user space.
  Micro Kernel: Bảo mật cao hơn vì kernel nhỏ, giảm thiểu bề mặt tấn công.
- Khả năng mở rộng:
  Monolithic Kernel: Khó mở rộng vì bất kỳ thay đổi nào cũng yêu cầu sửa đổi toàn bộ kernel.
  Micro Kernel: Dễ mở rộng hơn do có thể thêm dịch vụ mới mà không cần thay đổi kernel.
- Giao tiếp giữa các thành phần:
  Monolithic Kernel: Gọi hàm nội bộ (function calls) nhanh hơn nhưng khó kiểm soát lỗi.
  Micro Kernel: Sử dụng cơ chế IPC nên chậm hơn nhưng dễ kiểm soát lỗi.
- Hệ điều hành:
  Monolithic Kernel: Linux, Windows (trước Windows NT), Unix (truyền thống).
  Micro Kernel: QNX, MINIX, L4, Windows NT, MacOS (một phần).

![Image](https://github.com/Hoc-hh-2910/Linux_Course/blob/main/2_Key_Features/Microkernel_Vs_Monolithic_Kernel.jpg)

2. **Ưu điểm và nhược điểm giữa Monolithic Kernel và Micro Kernel:**

**Minolithic Kernel**
Ưu điểm:
- Hiệu suất cao: Do các thành phần chạy trực tiếp trong kernel mode, không cần giao tiếp qua IPC.
- Giao tiếp nhanh: Các thành phần có thể gọi trực tiếp các hàm của nhau thay vì thông qua tin nhắn IPC.
- Phổ biến: Được sử dụng rộng rãi trong các hệ điều hành phổ biến như Linux và Unix.
Nhược điểm:
- Ít ổn định hơn: Nếu một module gặp lỗi, toàn bộ hệ thống có thể bị crash.
- Bảo mật kém hơn: Kernel lớn làm tăng bề mặt tấn công.
- Khó mở rộng và bảo trì: Việc thay đổi hoặc thêm tính năng vào kernel có thể dẫn đến lỗi và cần biên dịch lại toàn bộ kernel.

**Micro Kernel**
Ưu điểm:
- Ổn định hơn: Nếu một dịch vụ gặp lỗi, chỉ dịch vụ đó bị ảnh hưởng, không làm sập toàn bộ hệ thống.
- Bảo mật cao hơn: Kernel nhỏ gọn, ít lỗ hổng bảo mật hơn.
- Dễ mở rộng: Có thể thêm hoặc sửa đổi các dịch vụ mà không ảnh hưởng đến kernel.
Nhược điểm:
- Hiệu suất thấp hơn: Việc giao tiếp giữa các thành phần qua IPC làm tăng độ trễ.
- Phức tạp hơn: Việc triển khai một hệ điều hành dựa trên Micro Kernel đòi hỏi cơ chế IPC và quản lý nhiều tiến trình, làm tăng độ phức tạp.
- Tốc độ phát triển chậm: Vì phải kiểm tra nhiều giao tiếp giữa các module.

3. Lí do Linux sử dụng Monolithic Kernel nhưng vẫn có tính linh hoạt cao:

Nhờ vào những cơ chế sau đây:

**Hỗ trợ Loadable Kernel Module (LKM)**
- Linux cho phép nạp hoặc gỡ bỏ các module hạt nhân động mà không cần biên dịch lại toàn bộ kernel hay khởi động lại hệ thống.
- Ví dụ: Trình điều khiển thiết bị (drivers), hệ thống tập tin, giao thức mạng có thể được thêm vào hoặc gỡ bỏ linh hoạt.
- Công cụ liên quan: insmod, rmmod, modprobe, lsmod.
-> Ưu điểm: Dễ dàng mở rộng tính năng mà không làm ảnh hưởng đến toàn bộ hệ thống.

**Kernel Configuration & Customization**
- Linux hỗ trợ tùy chỉnh kernel với Kconfig, giúp người dùng có thể:
  + Tắt/mở các thành phần kernel trước khi biên dịch.
  + Tối ưu kernel theo nhu cầu phần cứng và ứng dụng cụ thể.
- Các công cụ như make menuconfig giúp lựa chọn các tính năng cần thiết.
-> Ưu điểm: Kernel có thể được tối ưu cho các hệ thống nhúng, máy chủ, hoặc siêu máy tính.

**User Space & System Call Flexibility**
- Mặc dù Linux có kernel nguyên khối (monolithic), nhưng nó vẫn có rõ ràng sự phân tách giữa kernel space và user space.
- Các ứng dụng người dùng tương tác với kernel thông qua system calls mà không cần sửa đổi kernel.
- eBPF (Extended Berkeley Packet Filter): Cho phép chạy code trong kernel mà không cần thay đổi mã nguồn hạt nhân.
-> Ưu điểm: Hệ thống vẫn duy trì bảo mật và ổn định trong khi cho phép mở rộng tính năng.

**Namespace & Cgroups (Containerization)**
- Linux hỗ trợ container (ví dụ: Docker, LXC) mà không cần microkernel.
- Namespace: Cách ly tài nguyên như PID, network, filesystem cho từng tiến trình/container.
- Cgroups: Quản lý tài nguyên CPU, RAM, I/O, giúp hạn chế mức sử dụng tài nguyên của tiến trình.
-> Ưu điểm: Đạt được sự linh hoạt như microkernel nhưng vẫn giữ hiệu năng cao của monolithic kernel.
**Tính tương thích ngược & Module Interface Stable**
- Kernel Linux duy trì ABI (Application Binary Interface) ổn định, giúp driver hoặc module không cần thay đổi lớn khi cập nhật kernel.
- Hỗ trợ nhiều kiến trúc phần cứng từ x86, ARM, RISC-V, PowerPC...
-> Ưu điểm: Dễ dàng cập nhật kernel mà không phá vỡ hệ thống hiện tại.

# Bài 2. Mô hình "Everything as a File" trong Linux
1. Giải thích mô hình "Everything as a File":

Mô hình "Everything as a File" là một triết lý thiết kế quan trọng trong Linux và các hệ điều hành kiểu Unix. Theo mô hình này, hầu hết mọi thứ trong hệ thống – từ tệp dữ liệu thông thường đến thiết bị phần cứng và tiến trình – đều được biểu diễn dưới dạng tệp. Điều này giúp hệ điều hành có một giao diện thống nhất để tương tác với nhiều loại tài nguyên khác nhau.
**Lợi ích**:
- Đơn giản hóa hệ thống: Mọi thứ có thể được truy cập bằng cùng một tập lệnh (open, read, write).
- Dễ dàng lập trình: Chương trình có thể làm việc với các thiết bị như làm việc với tệp tin.
- Linh hoạt: Hỗ trợ giao tiếp giữa các tiến trình và quản lý thiết bị phần cứng một cách nhất quán.
- Bảo mật tốt hơn: Hệ thống phân quyền tệp (chmod, chown) có thể áp dụng cho tất cả tài nguyên.

2. Các đối tượng trong Linux hoạt động như file:

2.1 Tệp thông thường (Regular Files): Đây là các tệp chứa dữ liệu người dùng như tài liệu, mã nguồn, file nhị phân, ảnh, video... Chúng được lưu trữ trên đĩa theo cách thông thường.
Ví dụ:
```c
cat myfile.txt  # Đọc nội dung của tệp văn bản
```
2.2 Thư mục (Diẻctories): Trong Linux, thư mục cũng là một loại tệp đặc biệt, lưu trữ danh sách các tệp và thư mục con.
Ví dụ:
```c
ls -l /home/user  # Liệt kê nội dung thư mục
```
2.3 Tệp thiết bị (Device Files): Các thiết bị phần cứng như ổ đĩa, bàn phím, chuột, và cổng nối tiếp được biểu diễn dưới dạng tệp nằm trong thư mục **/dev**.
  - Tệp thiết bị ký tự (Character Devices): Giao tiếp với thiết bị theo từng byte (ví dụ: bàn phím, chuột, cổng serial).
  ```c
  cat /dev/tty   # Hiển thị đầu vào từ bàn phím (terminal)
  ```
  - Tệp thiết bị khối (Block Devices): Giao tiếp với thiết bị theo từng khối dữ liệu lớn (ví dụ: ổ cứng, USB).
  ```c
  ls -l /dev/sd*  # Liệt kê các ổ đĩa trên hệ thống
  ```
2.4 Tệp đặc biệt khác
**Pipe & Named Pipe (FIFO)**
+ Pipe (|) là một phương thức giao tiếp giữa các tiến trình.
  ```c
  ls -l | grep "txt"
  ```
+ Named Pipe (FIFO) là một tệp đặc biệt cho phép hai tiến trình giao tiếp thông qua một đường ống có tên.
  ```c
  mkfifo my_pipe
  echo "Hello" > my_pipe &
  cat my_pipe
  ```
**Tệp socket**
+ Dùng để giao tiếp giữa các tiến trình (IPC) hoặc qua mạng.
+ Ví dụ: /var/run/docker.sock cho Docker daemon.

**Tệp liên kết (Symbolic Links & Hard Links)**
+ Liên kết mềm (Symbolic Link): Tương tự shortcut trong Windows.
  ```c
  ln -s /etc/passwd my_link
  ```
+ Liên kết cứng (Hard Link): Tạo một tệp tham chiếu đến cùng dữ liệu trên ổ đĩa.
  ```c
  ln /etc/passwd my_hard_link
  ```

# Bài 3. Cách Linux thực hiện Pre-emptive Multitasking

1. Định nghĩa Pre-emptive Multitasking và phân biệt với Co-operative Multitasking:

**Pre-emptive Multitasking (Đa nhiệm ưu tiên)**
- Cách hoạt động: Hệ điều hành có quyền giành quyền kiểm soát từ tiến trình đang chạy và chuyển sang tiến trình khác dựa trên bộ lập lịch.
- Quản lý CPU: Kernel sử dụng bộ lập lịch (scheduler) để phân phối CPU dựa trên mức độ ưu tiên và thời gian chạy.
- Thời điểm chuyển ngữ cảnh: Khi hết thời gian CPU cho một tiến trình hoặc khi có sự kiện ưu tiên hơn (ví dụ: tiến trình có mức ưu tiên cao cần chạy ngay).
- **Ưu điểm:**
  + Đảm bảo tính công bằng giữa các tiến trình.
  + Phản hồi hệ thống nhanh hơn, tránh treo hệ thống do một tiến trình không nhả CPU.
- **Nhược điểm:**
  + Phức tạp hơn do cần cơ chế quản lý ngữ cảnh.
  + Có thể gây overhead do phải liên tục chuyển ngữ cảnh.

**Co-operative Multitasking (Đa nhiệm hợp tác)**
- Cách hoạt động: Mỗi tiến trình tự quyết định khi nào nhường quyền kiểm soát CPU cho tiến trình khác.
- Quản lý CPU: Không có sự can thiệp của kernel, mỗi tiến trình phải gọi một hàm đặc biệt (yield, sleep,…) để tự nhường CPU.
- Thời điểm chuyển ngữ cảnh: Chỉ xảy ra khi tiến trình tự nguyện nhả CPU.
- **Ưu điểm:**
  + Dễ lập trình hơn, không có overhead do chuyển ngữ cảnh bắt buộc.
  + Ít gây ra các vấn đề đồng bộ hóa dữ liệu giữa các tiến trình.
- **Nhược điểm:**
  + Nếu một tiến trình chiếm CPU quá lâu mà không nhả quyền, hệ thống có thể bị treo hoặc phản hồi chậm.
  + Không đảm bảo tính công bằng trong phân phối CPU.

2. Vai trò của Scheduler

Linux Scheduler đóng vai trò quan trọng trong việc quản lý đa nhiệm và cân bằng tải CPU theo các tiêu chí như ưu tiên, loại tiến trình, và thời gian sử dụng CPU.
- Phân phối CPU công bằng giữa các tiến trình.
- Đảm bảo thời gian phản hồi tốt cho các tiến trình quan trọng.
- Tối ưu hóa hiệu suất hệ thống, tránh tình trạng starvation (đói CPU).
- Hỗ trợ nhiều loại tiến trình khác nhau (real-time, interactive, batch, idle).

Thuật toán **Completely Fair Scheduler (CFS)** -Thuật toán lập lịch mặc định của Linux.
**CFS** không sử dụng mức ưu tiên tĩnh (static priority) như các thuật toán trước đây mà dựa vào khái niệm **vruntime** (thời gian chạy ảo) để quyết định tiến trình nào sẽ được lên lịch chạy tiếp theo.
- Khái niệm chính:
  + vruntime (virtual runtime): Mỗi tiến trình có một giá trị vruntime, biểu thị tổng thời gian CPU đã sử dụng.
  + Tiến trình có ```vruntime``` nhỏ nhất sẽ được chọn chạy tiếp theo.
  + CFS sử dụng cây đỏ-đen (Red-Black Tree) để quản lý các tiến trình, giúp tìm tiến trình có ```vruntime``` nhỏ nhất với độ phức tạp O(log N).
- Cách tính ```vruntime:```

              vruntime=vruntime+($delta_{exec}$ x $load_{weight}$)
          
​Trong đó:
- ```delta_exec```: Thời gian tiến trình thực sự chạy trên CPU.
- ```load_weight```: Trọng số ưu tiên (ưu tiên cao hơn thì ```load_weight``` cao, làm ```vruntime``` tăng chậm hơn).
- Giá trị ```vruntime``` của tiến trình được tăng lên dựa trên thời gian sử dụng CPU, giúp đảm bảo công bằng giữa các tiến trình.

***Các yếu tố ảnh hưởng đến Scheduling của CFS***

CFS lập lịch dựa trên các yếu tố sau:
| Yếu tố | Ảnh Hưởng |
| --- | --- |
| vruntime | Tiến trình có ```vruntime``` nhỏ nhất sẽ được chọn chạy. |
| Nice Value | Xác định độ ưu tiên, ảnh hưởng đến ```load_weight``` (từ -20 đến 19).|
| Cgroup | 	CFS có thể giới hạn tài nguyên CPU cho các nhóm tiến trình. |
| CPU Load | Nếu CPU quá tải, CFS điều chỉnh ```timeslice``` để phân bổ CPU hợp lý. |
| Multi-Core | CFS hỗ trợ cân bằng tải giữa các lõi CPU để tối ưu hiệu suất. |
