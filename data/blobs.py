"""
Generate two 2D Gaussian blobs for testing a logistic regression implementation.
Output CSV columns: x1, x2, label
"""

import csv
import random
import math

# ---- Tunable parameters ----
N_PER_CLASS = 50          # points per class
STD = 1.0                 # spread of each blob (raise to ~1.8 for some overlap)
SEED = 42                 # fixed seed => reproducible dataset
OUTPUT = "blobs.csv"

CLASS0_CENTER = (2.0, 2.0)
CLASS1_CENTER = (-2.0, -2.0)
# -----------------------------

random.seed(SEED)


def sample_blob(center, n, std):
    """Return n (x1, x2) points drawn from a 2D Gaussian around `center`."""
    cx, cy = center
    points = []
    for _ in range(n):
        x1 = random.gauss(cx, std)
        x2 = random.gauss(cy, std)
        points.append((x1, x2))
    return points


def main():
    class0 = [(x1, x2, 0) for (x1, x2) in sample_blob(CLASS0_CENTER, N_PER_CLASS, STD)]
    class1 = [(x1, x2, 1) for (x1, x2) in sample_blob(CLASS1_CENTER, N_PER_CLASS, STD)]

    rows = class0 + class1
    random.shuffle(rows)  # mix classes so the file isn't all-0s then all-1s

    with open(OUTPUT, "w", newline="") as f:
        writer = csv.writer(f)
        writer.writerow(["x1", "x2", "label"])
        for x1, x2, label in rows:
            writer.writerow([f"{x1:.6f}", f"{x2:.6f}", label])

    print(f"Wrote {len(rows)} samples to {OUTPUT}")


if __name__ == "__main__":
    main()