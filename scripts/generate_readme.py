from pathlib import Path
from collections import defaultdict
from datetime import datetime

stats = defaultdict(lambda: defaultdict(int))

for folder in Path(".").iterdir():
    if not folder.is_dir():
        continue

    readme = folder / "README.md"

    if not readme.exists():
        continue

    text = readme.read_text(encoding="utf-8", errors="ignore")

    difficulty = None

    if "Easy" in text:
        difficulty = "Easy"
    elif "Medium" in text:
        difficulty = "Medium"
    elif "Hard" in text:
        difficulty = "Hard"

    if difficulty is None:
        continue

    language = None

    for file in folder.iterdir():
        ext = file.suffix.lower()

        if ext == ".cpp":
            language = "C++"
        elif ext == ".cs":
            language = "C#"
        elif ext == ".sql":
            language = "SQL"
        elif ext == ".py":
            language = "Python"

    if language:
        stats[language][difficulty] += 1

lines = [
    "# LeetCode Solutions",
    "",
    "## Summary",
    "",
    "| Language | Easy | Medium | Hard | Total |",
    "|----------|------|--------|------|--------|",
]

grand_total = 0

for lang in sorted(stats.keys()):
    easy = stats[lang]["Easy"]
    medium = stats[lang]["Medium"]
    hard = stats[lang]["Hard"]

    total = easy + medium + hard
    grand_total += total

    lines.append(
        f"| {lang} | {easy} | {medium} | {hard} | {total} |"
    )

lines.extend([
    "",
    f"**Total Solved:** {grand_total}",
    "",
    f"Last Updated: {datetime.utcnow().strftime('%Y-%m-%d %H:%M UTC')}"
])

Path("README.md").write_text(
    "\n".join(lines),
    encoding="utf-8"
)