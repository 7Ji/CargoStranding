# Cargo Stranding / 货箱搁浅

## Build / 构建
Clone the project and run `make`  
克隆此项目，运行`make`
```
git clone https://github.com/7Ji/CargoStranding
cd CargoStranding
make
```
The result binary is `CargoStranding`  
构建的二进制文件为`CargoStranding`

## Usage / 使用
Run `./CargoStranding` to open the calculator to use its CLI  
运行`./CargoStranding`打开计算器来使用命令行界面

### Request / 请求
Enter `[Type]count(/total)(*duplicate)` to submit a request that represents a needed quantity for a certain material. Multiple requests with multiple types of materials can be cached, a same material could be repeated in multiple requests, each of them will be calculated seperatedly (e.g. a request of 43 metals and another request of 57 metals will result in 1 metals(50) and 1 metals(100), not a single metals(100)).  
输入`[类型]数量(/总数)(*重复数)`来提交对某一材料的一个需求数目。可以缓存多种材料的多个请求，同一个材料可以重复请求多次，每一个请求是分开计算的。（比如，一个43金属的请求和另一个57金属的请求，结果是一个金属(50)和一个金属(100)，不是一个金属(100)）

The type of the material is represented in the following characters:  
材料种类由以下单字母决定
 - `R` or `r` for resins  
 `R`或`r`为树脂
 - `M` or `m` for metals  
 `M`或`m`为金属
 - `C` (uppercase) for ceramics  
 `C`(大写)为陶瓷
 - `c` for chemicals  
 `c`(小写)为化学品
 - `S` or `s` for special alloys  
 `S`或`s`为特种合金

#### Examples / 例子
 - `M199` for 199 metals  
 `M199`表示199金属
 - `s1234/2600` for 1366 special alloys *so you don't need to calculate the missing part of a certain unfinished upgrade*  
 `s1234/2600`表示1366特种合金 *以此，你不必计算未完成的升级里缺的部分*
 - `c234*10` for 10 duplicated requests of 234 chemicals *so you don't need to enter multiple times*  
 `c234*10`为10个234化学品的重复请求 *以此，你不必手动填写多个重复请求*
 - `r100/2300*6` for 6 duplicated requests of 2200 resins  
 `r100/2300*6`表示6个2200树脂的重复请求

```
=> Material request 3 or command: S1234/4567*3
  => Requested Special Alloys * 3333 (3 duplicates)
  => Request 3: Special Alloys * 3333
    -> Special Alloys (1200) (XL, 120.0kg) * 2
    -> Special Alloys (960) (XL, 96.0kg) * 1
    -> Total weight: 336.0kg, total volume: 18
  => Request 4: Special Alloys * 3333
    -> Special Alloys (1200) (XL, 120.0kg) * 2
    -> Special Alloys (960) (XL, 96.0kg) * 1
    -> Total weight: 336.0kg, total volume: 18
  => Request 5: Special Alloys * 3333
    -> Special Alloys (1200) (XL, 120.0kg) * 2
    -> Special Alloys (960) (XL, 96.0kg) * 1
    -> Total weight: 336.0kg, total volume: 18
```

*Note: 1 single unit of volume equals the volume of a small cargo, so XL=6, L=4, M=2, S=1  
注意：一单位体积等于一个小号货物的大小，XL=6，L=4，M=2，S=1*

### Report / 报告
Enter `report` to get a full table of how many cargos of each quantity of each type of material should be carried like the following:  
输入`report`得到一张每种材料的每种数量的货物各应该携带多少个的表

```
=> Material request 1 or command: M1234
  => Requested Metals * 1234 (1 duplicates)
  => Request 1: Metals * 1234
    -> Metals (1000) (XL, 100.0kg) * 1
    -> Metals (400) (XL, 40.0kg) * 1
    -> Total weight: 140.0kg, total volume: 12
=> Material request 2 or command: S2345/6789*2
  => Requested Special Alloys * 4444 (2 duplicates)
  => Request 2: Special Alloys * 4444
    -> Special Alloys (1200) (XL, 120.0kg) * 3
    -> Special Alloys (960) (XL, 96.0kg) * 1
    -> Total weight: 456.0kg, total volume: 24
  => Request 3: Special Alloys * 4444
    -> Special Alloys (1200) (XL, 120.0kg) * 3
    -> Special Alloys (960) (XL, 96.0kg) * 1
    -> Total weight: 456.0kg, total volume: 24
=> Material request 4 or command: report
  => Needed variants for current requests:
==========================================================
 Type           |   S |   M |   L | XL1 | XL2 | XL3 | XL4 
==========================================================
 Metals         |  50 | 100 | 200 | 400 | 600 | 800 |1000 
----------------+-----+-----+-----+-----+-----+-----+-----
                |     |     |     |   1 |     |     |   1 
==========================================================
 Special Alloys |  60 | 120 | 240 | 480 | 720 | 960 |1200 
----------------+-----+-----+-----+-----+-----+-----+-----
                |     |     |     |     |     |   2 |   6 
==========================================================
  => Total weight: 1052.0 kg, total volume: 60
    -> Warning: weight >= 600.0kg, exceeding the max carry capability of one Floating Carrier Lv2!
    -> Warning: volume > 12 (=2XL=3L=6M=12S), exceeding the max carry capability of Reverse Trike!
    -> Warning: volume > 36 (=6XL=9L=18M=36S), exceeding the max carry capability of one Floating Carrier!
```

### List / 清单
Enter `list` to get a full list of submitted requests and how many cargos of each quantity of each type of material should be carried for each of them, and also their IDs so you could get an idea of what's submitted and possibly delete them with their IDs  
输入`list`来得到一份已提交请求的清单，以及每个请求应该携带多少个各数量的材料货物，还有这些请求的ID，以便你删除请求。
```
=> Material request 1 or command: C1234
  => Requested Ceramics * 1234 (1 duplicates)
  => Request 1: Ceramics * 1234
    -> Ceramics (800) (XL, 80.0kg) * 1
    -> Ceramics (480) (XL, 48.0kg) * 1
    -> Total weight: 128.0kg, total volume: 12
=> Material request 2 or command: c2345/6789*2
  => Requested Chemicals * 4444 (2 duplicates)
  => Request 2: Chemicals * 4444
    -> Chemicals (600) (XL, 60.0kg) * 7
    -> Chemicals (360) (XL, 36.0kg) * 1
    -> Total weight: 456.0kg, total volume: 48
  => Request 3: Chemicals * 4444
    -> Chemicals (600) (XL, 60.0kg) * 7
    -> Chemicals (360) (XL, 36.0kg) * 1
    -> Total weight: 456.0kg, total volume: 48
=> Material request 4 or command: list
  => Request 1: Ceramics * 1234
    -> Ceramics (800) (XL, 80.0kg) * 1
    -> Ceramics (480) (XL, 48.0kg) * 1
    -> Total weight: 128.0kg, total volume: 12
  => Request 2: Chemicals * 4444
    -> Chemicals (600) (XL, 60.0kg) * 7
    -> Chemicals (360) (XL, 36.0kg) * 1
    -> Total weight: 456.0kg, total volume: 48
  => Request 3: Chemicals * 4444
    -> Chemicals (600) (XL, 60.0kg) * 7
    -> Chemicals (360) (XL, 36.0kg) * 1
    -> Total weight: 456.0kg, total volume: 48
```
### Delete / 删除
Enter `delete [id]` to delete a submitted request  
输入`delete [id]`来删除一个已经提交的请求
```
=> Material request 1 or command: m100*2
  => Requested Metals * 100 (2 duplicates)
  => Request 1: Metals * 100
    -> Metals (100) (M, 10.0kg) * 1
    -> Total weight: 10.0kg, total volume: 2
  => Request 2: Metals * 100
    -> Metals (100) (M, 10.0kg) * 1
    -> Total weight: 10.0kg, total volume: 2
=> Material request 3 or command: c1
  => Requested Chemicals * 1 (1 duplicates)
  => Request 3: Chemicals * 1
    -> Chemicals (30) (S, 3.0kg) * 1
    -> Total weight: 3.0kg, total volume: 1
=> Material request 4 or command: C100
  => Requested Ceramics * 100 (1 duplicates)
  => Request 4: Ceramics * 100
    -> Ceramics (160) (L, 16.0kg) * 1
    -> Total weight: 16.0kg, total volume: 4
=> Material request 5 or command: list
  => Request 1: Metals * 100
    -> Metals (100) (M, 10.0kg) * 1
    -> Total weight: 10.0kg, total volume: 2
  => Request 2: Metals * 100
    -> Metals (100) (M, 10.0kg) * 1
    -> Total weight: 10.0kg, total volume: 2
  => Request 3: Chemicals * 1
    -> Chemicals (30) (S, 3.0kg) * 1
    -> Total weight: 3.0kg, total volume: 1
  => Request 4: Ceramics * 100
    -> Ceramics (160) (L, 16.0kg) * 1
    -> Total weight: 16.0kg, total volume: 4
=> Material request 5 or command: delete 3
  => Deleted request 3
=> Material request 4 or command: list
  => Request 1: Metals * 100
    -> Metals (100) (M, 10.0kg) * 1
    -> Total weight: 10.0kg, total volume: 2
  => Request 2: Metals * 100
    -> Metals (100) (M, 10.0kg) * 1
    -> Total weight: 10.0kg, total volume: 2
  => Request 3: Ceramics * 100
    -> Ceramics (160) (L, 16.0kg) * 1
    -> Total weight: 16.0kg, total volume: 4
```
### Clear / 清空
Enter `clear` to delete all requests  
输入`clear`来删除所有请求
```
=> Material request 1 or command: m1*265
  => Requested Metals * 1 (265 duplicates)
  => Request 1: Metals * 1
    -> Metals (50) (S, 5.0kg) * 1
    -> Total weight: 5.0kg, total volume: 1
  => Request 2: Metals * 1
    -> Metals (50) (S, 5.0kg) * 1
    -> Total weight: 5.0kg, total volume: 1
...
  => Request 265: Metals * 1
    -> Metals (50) (S, 5.0kg) * 1
    -> Total weight: 5.0kg, total volume: 1
=> Material request 266 or command: clear
  => Cleared 265 requests
=> Material request 1 or command:
```