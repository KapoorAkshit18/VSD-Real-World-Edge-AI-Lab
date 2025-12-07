
---

# 🚀 VSD – Real World Edge AI Lab

## 📌 About

This repository documents my work from the **Applied Edge AI Development Accelerator Program** by **VSD** using the **VSDSquadron Mini** and **VSDSquadron Pro** boards.
The goal of this project is to explore **Artificial Intelligence on low-power RISC-V devices** and understand how AI can be deployed on constrained embedded hardware.

---

## 🧠 AI vs Traditional Programming

### ✅ Traditional Logic

In traditional programming:

* We define rules manually.
* Execution is deterministic and predictable.
* Examples include C, C++, Python, and Assembly for low-level programming.

Example:
A simple RISC-V C program takes input and produces fixed output based on defined rules.

---

### ✅ Artificial Intelligence (AI)

AI systems learn patterns from data and make predictions instead of following hard-coded rules.

Example:

Instead of writing rules to detect a **cat or dog**, we train a model with image data and the model **learns patterns**.

**Challenges of AI on Embedded Systems:**

* Requires high computation
* Limited RAM and storage
* Power constraints
* Limited internet connectivity

---

## 🧩 VSDSquadron Boards Comparison

| Feature     | **VSDSquadron Mini**  | **VSDSquadron Pro**                  |
| ----------- | --------------------- | ------------------------------------ |
| SoC / Chip  | CH32V003F4U6 (RV32EC) | SiFive FE310-G002 (RV32IMAC)         |
| Clock Speed | 24 MHz                | 320 MHz                              |
| SRAM        | 2 KB                  | 16 KB Data + 16 KB Instruction Cache |
| Flash       | 16 KB (Internal)      | 4 MB (External SPI Flash)            |
| GPIO        | 15 Pins               | 19 Pins                              |
| PWM         | Available             | 9 PWM Pins                           |
| IDE         | PlatformIO (VSCode)   | Freedom Studio (Eclipse-based)       |
| Dimensions  | 50 × 28 mm            | 84 × 52 mm                           |

---

## ⚙️ Development Environment Setup (Cloud Lab)

This project uses **GitHub Codespaces** to run a cloud-based development desktop.

### 🔹 Steps

1. Open the repository template:

   ```
   https://github.com/vsdip/vsd-riscv-edgeai
   ```

2. Click **Code → Create Codespace on main**

3. Wait for the VS Code web interface

4. Go to the **Ports tab** and open the forwarded **noVNC Desktop**

5. In the terminal, run:

   ```bash
   cd ~/Desktop/FreedomStudio-3-1-1
   ./FreedomStudio
   ```

---

## 🛠 Important Tips

* Use **Chrome or Edge** for best VNC performance
* Do not close the Codespace while using Freedom Studio
* Files persist in: `/home/vscode/Desktop`

---

## ⚠️ Troubleshooting

| Issue                    | Solution                               |
| ------------------------ | -------------------------------------- |
| Port 6080 not visible    | Wait 2–3 minutes and refresh Ports tab |
| Blank noVNC screen       | Refresh browser tab                    |
| Freedom Studio not found | Restart Codespace or rerun setup       |
| Workspace popup repeats  | Select “Use this as default”           |

---

## 📈 Machine Learning Experiments

### 🔹 Linear Regression

Linear regression predicts continuous values by fitting a straight line that minimizes the distance from all data points.

Key idea:

* More data → Better fitting line
* Minimizes prediction error

### 🔹 Python Model Implementation

```python
class Model():
    def __init__(self, learning_rate, iterations):
        self.learning_rate = learning_rate
        self.iterations = iterations

    def predict(self, X):
        return X.dot(self.slope) + self.const

    def fit(self, X, Y):
        self.m, self.n = X.shape
        self.slope = np.zeros(self.n)
        self.const = 0
        self.X = X
        self.Y = Y

        for i in range(self.iterations):
            self.update_weights()
        return self

    def update_weights(self):
        Y_pred = self.predict(self.X)
        dW = -(2 * (self.X.T).dot(self.Y - Y_pred)) / self.m
        db = -2 * np.sum(self.Y - Y_pred) / self.m

        self.slope -= self.learning_rate * dW
        self.const -= self.learning_rate * db
        return self
```

---

## 📊 AI Lab – Results & Analysis

### 1. Logistic Regression (Binary Classification)

* Predicts whether a user purchases a product
* Features: **Age** and **Estimated Salary**

**Confusion Matrix:**

| Actual \ Predicted | 0  | 1  |
| ------------------ | -- | -- |
| 0                  | 66 | 2  |
| 1                  | 8  | 24 |

✅ High accuracy with very few misclassifications.

---

### 2. SVM Classifier

* Linear separator created between two classes
* Strong margin for separation
* Works well with linearly separable data

✅ High accuracy

---

### 3. KNN Classifier

#### Scaled Data:

* Smooth, curved decision boundaries
* Good performance

#### Unscaled Data:

* Poorer accuracy
* Shows importance of feature normalization

---

### 4. Linear Regression Output

* Best-fit line through data points
* Moderate prediction accuracy
* Relationship is only weakly linear

---

## ✅ Key Learnings

* Difference between **Regression vs Classification**
* Importance of **feature scaling**
* Real-world behavior of **SVM, KNN, and Linear Regression**
* How **decision boundaries** are formed

---

## 📌 Repository Link

```
https://github.com/KapoorAkshit18/VSD-Real-World-Edge-AI-Lab
```

---   