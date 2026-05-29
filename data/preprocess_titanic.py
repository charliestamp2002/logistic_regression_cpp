import pandas as pd

# Load raw Titanic data
df = pd.read_csv('titanic.csv')

# Select features to keep
features = ['Pclass', 'Sex', 'Age', 'SibSp', 'Parch', 'Fare']
target = 'Survived'

# Drop rows with missing values in selected columns
df = df[features + [target]].dropna()

# Encode Sex: male -> 0, female -> 1
df['Sex'] = df['Sex'].map({'male': 0, 'female': 1})

# Normalize numeric columns (min-max scaling)
for col in ['Age', 'Fare', 'Pclass', 'SibSp', 'Parch']:
    min_val = df[col].min()
    max_val = df[col].max()
    df[col] = (df[col] - min_val) / (max_val - min_val)

# Reorder so target is last column
df = df[features + [target]]

# Export to CSV without index or header
df.to_csv('titanic_clean.csv', index=False, header=False)

print(f"Exported {len(df)} samples to titanic_clean.csv")
print(f"Features: {features}")
print(f"Sample row: {df.iloc[0].tolist()}")
