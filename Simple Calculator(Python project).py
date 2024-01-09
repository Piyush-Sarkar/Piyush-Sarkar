import tkinter as tk
from math import sqrt

# Function to handle button clicks
def button_click(value):
    current = entry.get()

    # Clear button
    if value == "C":
        entry.delete(0, tk.END)
    # Equals button
    elif value == "=":
        try:
            result = eval(current)
            entry.delete(0, tk.END)
            entry.insert(tk.END, str(result))
        except Exception as e:
            entry.delete(0, tk.END)
            entry.insert(tk.END, "Error")
    # Backspace button
    elif value == "<-":
        current = current[:-1]
        entry.delete(0, tk.END)
        entry.insert(tk.END, current)
    # End button to close the application
    elif value == "End":
        window.destroy()
    # Exponent button
    elif value == "^":
        entry.insert(tk.END, "**")
    # Square root button
    elif value == "sqrt":
        entry.insert(tk.END, "sqrt(")
    # Opening bracket button
    elif value == "(":
        entry.insert(tk.END, "(")
    # Closing bracket button
    elif value == ")":
        entry.insert(tk.END, ")")
    # Percentage button
    elif value == "%":
        # Calculate percentage
        try:
            result = eval(current) / 100
            entry.delete(0, tk.END)
            entry.insert(tk.END, str(result))
        except Exception as e:
            entry.delete(0, tk.END)
            entry.insert(tk.END, "Error")
    # Numeric and operator buttons
    else:
        entry.insert(tk.END, value)

# Main Window and Widgets
window = tk.Tk()
window.title("Simple Calculator")
window.configure(bg="black")

# Entry widget to display the input and result
entry = tk.Entry(window, width=25, borderwidth=4, bg="black", fg="#EE1289", font=('Consolas', 14))
entry.grid(row=0, column=0, columnspan=4, padx=10, pady=10)

# Create buttons using a dictionary
buttons = {
    "7": (1, 0), "8": (1, 1), "9": (1, 2),
    "4": (2, 0), "5": (2, 1), "6": (2, 2),
    "1": (3, 0), "2": (3, 1), "3": (3, 2),
    "0": (4, 0), ".": (4, 1), "+": (4, 2),
    "-": (5, 0), "*": (5, 1), "/": (5, 2),
    "^": (6, 0), "sqrt": (6, 1), "=": (6, 2),
    "(": (7, 0), ")": (7, 1), "%": (7, 2),
    "C": (8, 0), "<-": (8, 1), "End": (8, 2)
}

# Place buttons in the grid
for text, pos in buttons.items():
    row, col = pos[:2]
    button = tk.Button(window, text=text, width=6, bd=5, command=lambda t=text: button_click(t), relief="raised", bg="#171717", fg="#FFB90F", font=('Consolas', 12))
    button.grid(row=row, column=col, padx=5, pady=5)
    if len(pos) == 3:
        button.grid(columnspan=pos[2])

# Set window transparency
window.attributes("-alpha", 0.9)

# Main loop
window.mainloop()
