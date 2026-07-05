import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("sine.csv")

plt.plot(df["time"], df["sample"])
plt.grid(True)
plt.xlabel("Time (s)")
plt.ylabel("Amplitude")
plt.title("50 MHz Sine Wave")
plt.show()