# stm32-labview-digital-scale
烟台大学检测技术实验：STM32 通过 HX711 采集重量，在 OLED 上显示读数，并通过串口发送给 LabVIEW，实现实时称重可视化和可设阈值的超重报警。
# 基于 STM32 与 LabVIEW 的电子秤

本项目包含 STM32 固件和 LabVIEW 上位机工程，适合学习从称重传感器采集、
重量标定到串口通信、上位机显示和报警的完整流程。

- STM32 端：通过 HX711 采集称重数据，启动时记录零点，按标定参数换算重量。
  OLED 显示重量和采样原始值，串口约每 500 ms 发送一次重量。
- LabVIEW 端：通过 NI-VISA 接收串口数据，实时显示重量，并在重量超过设定阈值时报警。

## 工程结构

- `firmware/`：STM32 固件，用 Keil MDK 打开 `Project.uvprojx`。
- `labview/`：LabVIEW 上位机工程和对应的 `.vi` 文件。
- 口波特率为 9600，重量以保留两位小数的文本发送，当前固件没有在每条重量数据后发送换行符。
- <img width="1232" height="641" alt="3e80ac41507f9dbaba7e9f7fb5b84ac9" src="https://github.com/user-attachments/assets/916a0563-73bd-457b-943f-1b60e2a18a1b" />
