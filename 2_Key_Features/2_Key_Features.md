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

![Image](https://github.com/Hoc-hh-2910/Linux_Course/blob/main/2_Key_Features/Preemptive-Cooperative.png)

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

# Thực hành:
[Video Practice](https://drive.google.com/file/d/1UUGstKZdaApgX7n14_s32sPAEaCUDz4H/view?usp=sharing)

**Liệt kê các thiết bị trong /dev**
```c
hochh@hochh-VirtualBox:~/Linux_Course/2_Key_Feature$ ls -l /dev
total 0
crw-r--r--   1 root  root     10, 235 Feb 15 18:17 autofs
drwxr-xr-x   2 root  root         440 Feb 15 18:19 block
drwxr-xr-x   2 root  root          80 Feb 15 18:17 bsg
crw-------   1 root  root     10, 234 Feb 15 18:17 btrfs-control
drwxr-xr-x   3 root  root          60 Feb 15 18:17 bus
lrwxrwxrwx   1 root  root           3 Feb 15 18:17 cdrom -> sr0
drwxr-xr-x   2 root  root        3760 Feb 15 18:17 char
crw--w----   1 root  tty       5,   1 Feb 15 18:17 console
lrwxrwxrwx   1 root  root          11 Feb 15 18:17 core -> /proc/kcore
drwxr-xr-x   6 root  root         120 Feb 15 18:17 cpu
crw-------   1 root  root     10, 123 Feb 15 18:17 cpu_dma_latency
crw-------   1 root  root     10, 203 Feb 15 18:17 cuse
drwxr-xr-x  10 root  root         200 Feb 15 18:17 disk
drwxr-xr-x   2 root  root          60 Feb 15 18:17 dma_heap
drwxr-xr-x   3 root  root         100 Feb 15 18:17 dri
crw-------   1 root  root     10, 125 Feb 15 18:17 ecryptfs
crw-rw----   1 root  video    29,   0 Feb 15 18:17 fb0
lrwxrwxrwx   1 root  root          13 Feb 15 18:17 fd -> /proc/self/fd
crw-rw-rw-   1 root  root      1,   7 Feb 15 18:17 full
crw-rw-rw-   1 root  root     10, 229 Feb 15 18:17 fuse
crw-------   1 root  root    241,   0 Feb 15 18:17 hidraw0
crw-------   1 root  root     10, 228 Feb 15 18:17 hpet
drwxr-xr-x   2 root  root           0 Feb 15 18:17 hugepages
crw-------   1 root  root     10, 183 Feb 15 18:17 hwrng
crw-------   1 root  root     89,   0 Feb 15 18:17 i2c-0
lrwxrwxrwx   1 root  root          12 Feb 15 18:17 initctl -> /run/initctl
drwxr-xr-x   4 root  root         340 Feb 15 18:17 input
crw-r--r--   1 root  root      1,  11 Feb 15 18:17 kmsg
lrwxrwxrwx   1 root  root          28 Feb 15 18:17 log -> /run/systemd/journal/dev-log
crw-rw----   1 root  disk     10, 237 Feb 15 18:17 loop-control
brw-rw----   1 root  disk      7,   0 Feb 15 18:17 loop0
brw-rw----   1 root  disk      7,   1 Feb 15 18:17 loop1
brw-rw----   1 root  disk      7,  10 Feb 15 18:17 loop10
brw-rw----   1 root  disk      7,  11 Feb 15 18:17 loop11
brw-rw----   1 root  disk      7,  12 Feb 15 18:17 loop12
brw-rw----   1 root  disk      7,  13 Feb 15 18:17 loop13
brw-rw----   1 root  disk      7,  14 Feb 15 18:17 loop14
brw-rw----   1 root  disk      7,  15 Feb 15 18:19 loop15
brw-rw----   1 root  disk      7,   2 Feb 15 18:17 loop2
brw-rw----   1 root  disk      7,   3 Feb 15 18:17 loop3
brw-rw----   1 root  disk      7,   4 Feb 15 18:17 loop4
brw-rw----   1 root  disk      7,   5 Feb 15 18:17 loop5
brw-rw----   1 root  disk      7,   6 Feb 15 18:17 loop6
brw-rw----   1 root  disk      7,   7 Feb 15 18:17 loop7
brw-rw----   1 root  disk      7,   8 Feb 15 18:17 loop8
brw-rw----   1 root  disk      7,   9 Feb 15 18:17 loop9
drwxr-xr-x   2 root  root          60 Feb 15 18:17 mapper
crw-------   1 root  root     10, 227 Feb 15 18:17 mcelog
crw-r-----   1 root  kmem      1,   1 Feb 15 18:17 mem
drwxrwxrwt   2 root  root          40 Feb 15 18:17 mqueue
drwxr-xr-x   2 root  root          60 Feb 15 18:17 net
crw-rw-rw-   1 root  root      1,   3 Feb 15 18:17 null
crw-------   1 root  root     10, 144 Feb 15 18:17 nvram
crw-r-----   1 root  kmem      1,   4 Feb 15 18:17 port
crw-------   1 root  root    108,   0 Feb 15 18:17 ppp
crw-------   1 root  root     10,   1 Feb 15 18:17 psaux
crw-rw-rw-   1 root  tty       5,   2 Feb 15 18:35 ptmx
drwxr-xr-x   2 root  root           0 Feb 15 18:17 pts
crw-rw-rw-   1 root  root      1,   8 Feb 15 18:17 random
crw-rw-r--+  1 root  root     10, 242 Feb 15 18:17 rfkill
lrwxrwxrwx   1 root  root           4 Feb 15 18:17 rtc -> rtc0
crw-------   1 root  root    248,   0 Feb 15 18:17 rtc0
brw-rw----   1 root  disk      8,   0 Feb 15 18:17 sda
brw-rw----   1 root  disk      8,   1 Feb 15 18:17 sda1
brw-rw----   1 root  disk      8,   2 Feb 15 18:17 sda2
crw-rw----+  1 root  cdrom    21,   0 Feb 15 18:17 sg0
crw-rw----   1 root  disk     21,   1 Feb 15 18:17 sg1
drwxrwxrwt   2 root  root          40 Feb 15 18:17 shm
crw-------   1 root  root     10, 231 Feb 15 18:17 snapshot
drwxr-xr-x   3 root  root         180 Feb 15 18:17 snd
brw-rw----+  1 root  cdrom    11,   0 Feb 15 18:17 sr0
lrwxrwxrwx   1 root  root          15 Feb 15 18:17 stderr -> /proc/self/fd/2
lrwxrwxrwx   1 root  root          15 Feb 15 18:17 stdin -> /proc/self/fd/0
lrwxrwxrwx   1 root  root          15 Feb 15 18:17 stdout -> /proc/self/fd/1
crw-rw-rw-   1 root  tty       5,   0 Feb 15 18:17 tty
crw--w----   1 root  tty       4,   0 Feb 15 18:17 tty0
crw--w----   1 root  tty       4,   1 Feb 15 18:17 tty1
crw--w----   1 root  tty       4,  10 Feb 15 18:17 tty10
crw--w----   1 root  tty       4,  11 Feb 15 18:17 tty11
crw--w----   1 root  tty       4,  12 Feb 15 18:17 tty12
crw--w----   1 root  tty       4,  13 Feb 15 18:17 tty13
crw--w----   1 root  tty       4,  14 Feb 15 18:17 tty14
crw--w----   1 root  tty       4,  15 Feb 15 18:17 tty15
crw--w----   1 root  tty       4,  16 Feb 15 18:17 tty16
crw--w----   1 root  tty       4,  17 Feb 15 18:17 tty17
crw--w----   1 root  tty       4,  18 Feb 15 18:17 tty18
crw--w----   1 root  tty       4,  19 Feb 15 18:17 tty19
crw--w----   1 hochh tty       4,   2 Feb 15 18:17 tty2
crw--w----   1 root  tty       4,  20 Feb 15 18:17 tty20
crw--w----   1 root  tty       4,  21 Feb 15 18:17 tty21
crw--w----   1 root  tty       4,  22 Feb 15 18:17 tty22
crw--w----   1 root  tty       4,  23 Feb 15 18:17 tty23
crw--w----   1 root  tty       4,  24 Feb 15 18:17 tty24
crw--w----   1 root  tty       4,  25 Feb 15 18:17 tty25
crw--w----   1 root  tty       4,  26 Feb 15 18:17 tty26
crw--w----   1 root  tty       4,  27 Feb 15 18:17 tty27
crw--w----   1 root  tty       4,  28 Feb 15 18:17 tty28
crw--w----   1 root  tty       4,  29 Feb 15 18:17 tty29
crw--w----   1 root  tty       4,   3 Feb 15 18:17 tty3
crw--w----   1 root  tty       4,  30 Feb 15 18:17 tty30
crw--w----   1 root  tty       4,  31 Feb 15 18:17 tty31
crw--w----   1 root  tty       4,  32 Feb 15 18:17 tty32
crw--w----   1 root  tty       4,  33 Feb 15 18:17 tty33
crw--w----   1 root  tty       4,  34 Feb 15 18:17 tty34
crw--w----   1 root  tty       4,  35 Feb 15 18:17 tty35
crw--w----   1 root  tty       4,  36 Feb 15 18:17 tty36
crw--w----   1 root  tty       4,  37 Feb 15 18:17 tty37
crw--w----   1 root  tty       4,  38 Feb 15 18:17 tty38
crw--w----   1 root  tty       4,  39 Feb 15 18:17 tty39
crw--w----   1 root  tty       4,   4 Feb 15 18:17 tty4
crw--w----   1 root  tty       4,  40 Feb 15 18:17 tty40
crw--w----   1 root  tty       4,  41 Feb 15 18:17 tty41
crw--w----   1 root  tty       4,  42 Feb 15 18:17 tty42
crw--w----   1 root  tty       4,  43 Feb 15 18:17 tty43
crw--w----   1 root  tty       4,  44 Feb 15 18:17 tty44
crw--w----   1 root  tty       4,  45 Feb 15 18:17 tty45
crw--w----   1 root  tty       4,  46 Feb 15 18:17 tty46
crw--w----   1 root  tty       4,  47 Feb 15 18:17 tty47
crw--w----   1 root  tty       4,  48 Feb 15 18:17 tty48
crw--w----   1 root  tty       4,  49 Feb 15 18:17 tty49
crw--w----   1 root  tty       4,   5 Feb 15 18:17 tty5
crw--w----   1 root  tty       4,  50 Feb 15 18:17 tty50
crw--w----   1 root  tty       4,  51 Feb 15 18:17 tty51
crw--w----   1 root  tty       4,  52 Feb 15 18:17 tty52
crw--w----   1 root  tty       4,  53 Feb 15 18:17 tty53
crw--w----   1 root  tty       4,  54 Feb 15 18:17 tty54
crw--w----   1 root  tty       4,  55 Feb 15 18:17 tty55
crw--w----   1 root  tty       4,  56 Feb 15 18:17 tty56
crw--w----   1 root  tty       4,  57 Feb 15 18:17 tty57
crw--w----   1 root  tty       4,  58 Feb 15 18:17 tty58
crw--w----   1 root  tty       4,  59 Feb 15 18:17 tty59
crw--w----   1 root  tty       4,   6 Feb 15 18:17 tty6
crw--w----   1 root  tty       4,  60 Feb 15 18:17 tty60
crw--w----   1 root  tty       4,  61 Feb 15 18:17 tty61
crw--w----   1 root  tty       4,  62 Feb 15 18:17 tty62
crw--w----   1 root  tty       4,  63 Feb 15 18:17 tty63
crw--w----   1 root  tty       4,   7 Feb 15 18:17 tty7
crw--w----   1 root  tty       4,   8 Feb 15 18:17 tty8
crw--w----   1 root  tty       4,   9 Feb 15 18:17 tty9
crw-rw----   1 root  dialout   4,  64 Feb 15 18:17 ttyS0
crw-rw----   1 root  dialout   4,  65 Feb 15 18:17 ttyS1
crw-rw----   1 root  dialout   4,  74 Feb 15 18:17 ttyS10
crw-rw----   1 root  dialout   4,  75 Feb 15 18:17 ttyS11
crw-rw----   1 root  dialout   4,  76 Feb 15 18:17 ttyS12
crw-rw----   1 root  dialout   4,  77 Feb 15 18:17 ttyS13
crw-rw----   1 root  dialout   4,  78 Feb 15 18:17 ttyS14
crw-rw----   1 root  dialout   4,  79 Feb 15 18:17 ttyS15
crw-rw----   1 root  dialout   4,  80 Feb 15 18:17 ttyS16
crw-rw----   1 root  dialout   4,  81 Feb 15 18:17 ttyS17
crw-rw----   1 root  dialout   4,  82 Feb 15 18:17 ttyS18
crw-rw----   1 root  dialout   4,  83 Feb 15 18:17 ttyS19
crw-rw----   1 root  dialout   4,  66 Feb 15 18:17 ttyS2
crw-rw----   1 root  dialout   4,  84 Feb 15 18:17 ttyS20
crw-rw----   1 root  dialout   4,  85 Feb 15 18:17 ttyS21
crw-rw----   1 root  dialout   4,  86 Feb 15 18:17 ttyS22
crw-rw----   1 root  dialout   4,  87 Feb 15 18:17 ttyS23
crw-rw----   1 root  dialout   4,  88 Feb 15 18:17 ttyS24
crw-rw----   1 root  dialout   4,  89 Feb 15 18:17 ttyS25
crw-rw----   1 root  dialout   4,  90 Feb 15 18:17 ttyS26
crw-rw----   1 root  dialout   4,  91 Feb 15 18:17 ttyS27
crw-rw----   1 root  dialout   4,  92 Feb 15 18:17 ttyS28
crw-rw----   1 root  dialout   4,  93 Feb 15 18:17 ttyS29
crw-rw----   1 root  dialout   4,  67 Feb 15 18:17 ttyS3
crw-rw----   1 root  dialout   4,  94 Feb 15 18:17 ttyS30
crw-rw----   1 root  dialout   4,  95 Feb 15 18:17 ttyS31
crw-rw----   1 root  dialout   4,  68 Feb 15 18:17 ttyS4
crw-rw----   1 root  dialout   4,  69 Feb 15 18:17 ttyS5
crw-rw----   1 root  dialout   4,  70 Feb 15 18:17 ttyS6
crw-rw----   1 root  dialout   4,  71 Feb 15 18:17 ttyS7
crw-rw----   1 root  dialout   4,  72 Feb 15 18:17 ttyS8
crw-rw----   1 root  dialout   4,  73 Feb 15 18:17 ttyS9
crw-------   1 root  root      5,   3 Feb 15 18:17 ttyprintk
crw-rw----   1 root  kvm      10, 124 Feb 15 18:17 udmabuf
crw-------   1 root  root     10, 239 Feb 15 18:17 uhid
crw-------   1 root  root     10, 223 Feb 15 18:17 uinput
crw-rw-rw-   1 root  root      1,   9 Feb 15 18:17 urandom
crw-------   1 root  root     10, 126 Feb 15 18:17 userfaultfd
crw-------   1 root  root     10, 240 Feb 15 18:17 userio
crw-------   1 root  root     10, 122 Feb 15 18:17 vboxguest
crw-------   1 root  root     10, 121 Feb 15 18:17 vboxuser
crw-rw----   1 root  tty       7,   0 Feb 15 18:17 vcs
crw-rw----   1 root  tty       7,   1 Feb 15 18:17 vcs1
crw-rw----   1 root  tty       7,   2 Feb 15 18:17 vcs2
crw-rw----   1 root  tty       7,   3 Feb 15 18:17 vcs3
crw-rw----   1 root  tty       7,   4 Feb 15 18:17 vcs4
crw-rw----   1 root  tty       7,   5 Feb 15 18:17 vcs5
crw-rw----   1 root  tty       7,   6 Feb 15 18:17 vcs6
crw-rw----   1 root  tty       7, 128 Feb 15 18:17 vcsa
crw-rw----   1 root  tty       7, 129 Feb 15 18:17 vcsa1
crw-rw----   1 root  tty       7, 130 Feb 15 18:17 vcsa2
crw-rw----   1 root  tty       7, 131 Feb 15 18:17 vcsa3
crw-rw----   1 root  tty       7, 132 Feb 15 18:17 vcsa4
crw-rw----   1 root  tty       7, 133 Feb 15 18:17 vcsa5
crw-rw----   1 root  tty       7, 134 Feb 15 18:17 vcsa6
crw-rw----   1 root  tty       7,  64 Feb 15 18:17 vcsu
crw-rw----   1 root  tty       7,  65 Feb 15 18:17 vcsu1
crw-rw----   1 root  tty       7,  66 Feb 15 18:17 vcsu2
crw-rw----   1 root  tty       7,  67 Feb 15 18:17 vcsu3
crw-rw----   1 root  tty       7,  68 Feb 15 18:17 vcsu4
crw-rw----   1 root  tty       7,  69 Feb 15 18:17 vcsu5
crw-rw----   1 root  tty       7,  70 Feb 15 18:17 vcsu6
drwxr-xr-x   2 root  root          60 Feb 15 18:17 vfio
crw-------   1 root  root     10, 127 Feb 15 18:17 vga_arbiter
crw-------   1 root  root     10, 137 Feb 15 18:17 vhci
crw-rw----   1 root  kvm      10, 238 Feb 15 18:17 vhost-net
crw-rw----   1 root  kvm      10, 241 Feb 15 18:17 vhost-vsock
crw-rw-rw-   1 root  root      1,   5 Feb 15 18:17 zero
crw-------   1 root  root     10, 249 Feb 15 18:17 zfs
```

**Kiểm tra thông tin CPU**
```c
hochh@hochh-VirtualBox:~/Linux_Course/2_Key_Feature$ cat /proc/cpuinfo
processor	: 0
vendor_id	: GenuineIntel
cpu family	: 6
model		: 158
model name	: Intel(R) Core(TM) i5-9300H CPU @ 2.40GHz
stepping	: 13
microcode	: 0xde
cpu MHz		: 2400.002
cache size	: 8192 KB
physical id	: 0
siblings	: 4
core id		: 0
cpu cores	: 4
apicid		: 0
initial apicid	: 0
fpu		: yes
fpu_exception	: yes
cpuid level	: 22
wp		: yes
flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rdtscp lm constant_tsc rep_good nopl xtopology nonstop_tsc cpuid tsc_known_freq pni pclmulqdq ssse3 fma cx16 pcid sse4_1 sse4_2 x2apic movbe popcnt aes xsave avx f16c rdrand hypervisor lahf_lm abm 3dnowprefetch pti fsgsbase bmi1 avx2 bmi2 invpcid rdseed adx clflushopt arat md_clear flush_l1d arch_capabilities
bugs		: cpu_meltdown spectre_v1 spectre_v2 spec_store_bypass l1tf mds swapgs itlb_multihit srbds mmio_stale_data retbleed gds bhi
bogomips	: 4800.00
clflush size	: 64
cache_alignment	: 64
address sizes	: 39 bits physical, 48 bits virtual
power management:

processor	: 1
vendor_id	: GenuineIntel
cpu family	: 6
model		: 158
model name	: Intel(R) Core(TM) i5-9300H CPU @ 2.40GHz
stepping	: 13
microcode	: 0xde
cpu MHz		: 2400.002
cache size	: 8192 KB
physical id	: 0
siblings	: 4
core id		: 1
cpu cores	: 4
apicid		: 1
initial apicid	: 1
fpu		: yes
fpu_exception	: yes
cpuid level	: 22
wp		: yes
flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rdtscp lm constant_tsc rep_good nopl xtopology nonstop_tsc cpuid tsc_known_freq pni pclmulqdq ssse3 fma cx16 pcid sse4_1 sse4_2 x2apic movbe popcnt aes xsave avx f16c rdrand hypervisor lahf_lm abm 3dnowprefetch pti fsgsbase bmi1 avx2 bmi2 invpcid rdseed adx clflushopt arat md_clear flush_l1d arch_capabilities
bugs		: cpu_meltdown spectre_v1 spectre_v2 spec_store_bypass l1tf mds swapgs itlb_multihit srbds mmio_stale_data retbleed gds bhi
bogomips	: 4800.00
clflush size	: 64
cache_alignment	: 64
address sizes	: 39 bits physical, 48 bits virtual
power management:

processor	: 2
vendor_id	: GenuineIntel
cpu family	: 6
model		: 158
model name	: Intel(R) Core(TM) i5-9300H CPU @ 2.40GHz
stepping	: 13
microcode	: 0xde
cpu MHz		: 2400.002
cache size	: 8192 KB
physical id	: 0
siblings	: 4
core id		: 2
cpu cores	: 4
apicid		: 2
initial apicid	: 2
fpu		: yes
fpu_exception	: yes
cpuid level	: 22
wp		: yes
flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rdtscp lm constant_tsc rep_good nopl xtopology nonstop_tsc cpuid tsc_known_freq pni pclmulqdq ssse3 fma cx16 pcid sse4_1 sse4_2 x2apic movbe popcnt aes xsave avx f16c rdrand hypervisor lahf_lm abm 3dnowprefetch pti fsgsbase bmi1 avx2 bmi2 invpcid rdseed adx clflushopt arat md_clear flush_l1d arch_capabilities
bugs		: cpu_meltdown spectre_v1 spectre_v2 spec_store_bypass l1tf mds swapgs itlb_multihit srbds mmio_stale_data retbleed gds bhi
bogomips	: 4800.00
clflush size	: 64
cache_alignment	: 64
address sizes	: 39 bits physical, 48 bits virtual
power management:

processor	: 3
vendor_id	: GenuineIntel
cpu family	: 6
model		: 158
model name	: Intel(R) Core(TM) i5-9300H CPU @ 2.40GHz
stepping	: 13
microcode	: 0xde
cpu MHz		: 2400.002
cache size	: 8192 KB
physical id	: 0
siblings	: 4
core id		: 3
cpu cores	: 4
apicid		: 3
initial apicid	: 3
fpu		: yes
fpu_exception	: yes
cpuid level	: 22
wp		: yes
flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rdtscp lm constant_tsc rep_good nopl xtopology nonstop_tsc cpuid tsc_known_freq pni pclmulqdq ssse3 fma cx16 pcid sse4_1 sse4_2 x2apic movbe popcnt aes xsave avx f16c rdrand hypervisor lahf_lm abm 3dnowprefetch pti fsgsbase bmi1 avx2 bmi2 invpcid rdseed adx clflushopt arat md_clear flush_l1d arch_capabilities
bugs		: cpu_meltdown spectre_v1 spectre_v2 spec_store_bypass l1tf mds swapgs itlb_multihit srbds mmio_stale_data retbleed gds bhi
bogomips	: 4800.00
clflush size	: 64
cache_alignment	: 64
address sizes	: 39 bits physical, 48 bits virtual
power management:
```

**Kiểm tra thông tin trong bộ nhớ**
```c
hochh@hochh-VirtualBox:~/Linux_Course/2_Key_Feature$ cat /proc/meminfo
MemTotal:        8292304 kB
MemFree:         5227000 kB
MemAvailable:    6535208 kB
Buffers:           47712 kB
Cached:          1499988 kB
SwapCached:            0 kB
Active:          2003364 kB
Inactive:         753716 kB
Active(anon):    1256592 kB
Inactive(anon):        0 kB
Active(file):     746772 kB
Inactive(file):   753716 kB
Unevictable:          16 kB
Mlocked:              16 kB
SwapTotal:       4194300 kB
SwapFree:        4194300 kB
Zswap:                 0 kB
Zswapped:              0 kB
Dirty:                 0 kB
Writeback:             0 kB
AnonPages:       1209464 kB
Mapped:           441576 kB
Shmem:             47212 kB
KReclaimable:      54392 kB
Slab:             185256 kB
SReclaimable:      54392 kB
SUnreclaim:       130864 kB
KernelStack:        9536 kB
PageTables:        19032 kB
SecPageTables:         0 kB
NFS_Unstable:          0 kB
Bounce:                0 kB
WritebackTmp:          0 kB
CommitLimit:     8340452 kB
Committed_AS:    5420896 kB
VmallocTotal:   34359738367 kB
VmallocUsed:       27168 kB
VmallocChunk:          0 kB
Percpu:             2656 kB
HardwareCorrupted:     0 kB
AnonHugePages:         0 kB
ShmemHugePages:        0 kB
ShmemPmdMapped:        0 kB
FileHugePages:         0 kB
FilePmdMapped:         0 kB
Unaccepted:            0 kB
HugePages_Total:       0
HugePages_Free:        0
HugePages_Rsvd:        0
HugePages_Surp:        0
Hugepagesize:       2048 kB
Hugetlb:               0 kB
DirectMap4k:      117836 kB
DirectMap2M:     8435712 kB
```

**Ghi dữ liệu vào /dev/null**
```c
hochh@hochh-VirtualBox:~/Linux_Course/2_Key_Feature$ echo "Test" > /dev/null //Ghi vào thư mục "NULL" trong /dev nên sẽ không có file mới trong /dev
```
