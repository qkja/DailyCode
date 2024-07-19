import numpy as np
import matplotlib.pyplot as plt
import matplotlib
matplotlib.use('TkAgg')
plt.rcParams['font.sans-serif'] = ['SimHei']  # 用来正常显示中文标签
plt.rcParams['axes.unicode_minus'] = False  # 用来正常显示符号

Fs = 1000   # 采样频率
T = 1 / Fs  # 采样周期
L = 1000    # 信号长度
t = [i * T for i in range(L)]
t = np.array(t)
S = 0.2 + 0.7 * np.cos(2 * np.pi * 50 * t + 20 / 180 * np.pi) + 0.2 * np.cos(2 * np.pi * 100 * t + 70 / 180 * np.pi)
complex_array = np.fft.fft(S)
plt.subplot(311)
plt.grid(linestyle=':')
plt.plot(1000 * t[1:51], S[1:51], label='S')  # y是1000个相加后的正弦序列
plt.xlabel("t(毫秒)")
plt.ylabel("S(t)幅值")
plt.title("叠加信号图")
# plt.legend()
plt.show()
