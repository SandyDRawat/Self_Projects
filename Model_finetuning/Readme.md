# Chinese to English Translation Model

[![Open In Colab](https://colab.research.google.com/assets/colab-badge.svg)](https://colab.research.google.com/github/your-username/your-repo/blob/main/your-notebook.ipynb)

This repository contains a Chinese-to-English neural machine translation model built using Llama 3.2 3B and Unsloth for efficient fine-tuning. The model is designed to translate Chinese text to English with high accuracy.

## Overview

This project fine-tunes the Llama 3.2 3B model using Parameter-Efficient Fine-Tuning (PEFT) and Low-Rank Adaptation (LoRA) techniques to create a specialized Chinese-to-English translator. The implementation uses Unsloth for memory-efficient training and fast inference.

## Model Features

- Based on Llama 3.2 3B architecture
- Quantized with 4-bit precision for memory efficiency
- Fine-tuned with LoRA for optimal parameter efficiency
- Supports translations of various text lengths and complexities
- Available in multiple formats (LoRA adapters, 16-bit, and GGUF)

## Setup and Dependencies

```bash
pip install unsloth evaluate transformers nltk trl bitsandbytes peft
pip install sympy --upgrade
pip install llama-cpp-python
pip install --upgrade --no-cache-dir --no-deps git+https://github.com/unslothai/unsloth.git
```

Additionally, you'll need:
- Hugging Face account and token for model access
- GPU for faster training (T4 or better recommended)
- Access to the Chinese-English translation dataset

## Usage

### Training the Model

The notebook provides a complete pipeline for:
1. Loading and formatting a Chinese-English dataset
2. Configuring the model with PEFT/LoRA for efficient fine-tuning
3. Training the model with optimized parameters
4. Saving the model in various formats
5. Evaluating translation quality with BLEU scores

### Translation Example

```python
# Define the translation prompt
translation_prompt = """Below is a Chinese text that needs to be translated into English.

### Chinese Text:
{}

### English Translation:
{}"""

# Format the input
formatted_input = translation_prompt.format("你的模型可以翻译中文吗？", "")

# Generate translation with the model
outputs = model.generate(**inputs, max_new_tokens=512, use_cache=True)
translation = tokenizer.batch_decode(outputs)
```

### Inference with Llama-cpp

For deployable inference, the model is also available in GGUF format:

```python
from llama_cpp import Llama

# Load the model
llm = Llama.from_pretrained(
    repo_id="Rawsand/llama3.1_zhtoen_translation_v4_gguf",
    filename="unsloth.Q8_0.gguf",
)

# Translate text
text = "你的模型可以翻译中文吗？"
formatted_prompt = translation_prompt.format(text, "")
output = llm(formatted_prompt, max_tokens=512, echo=True)
translation = output['choices'][0]['text']
```

## Model Versions

- **LoRA adapters**: `Rawsand/llama3.1_zhtoen_translation_v4`
- **GGUF (8-bit Q8_0)**: `Rawsand/llama3.1_zhtoen_translation_v4_gguf`

## Evaluation

The model is evaluated using BLEU scores on a held-out test set. The notebook includes code for:
- Generating translations for evaluation samples
- Computing BLEU scores for individual translations
- Calculating average BLEU score across the test set

## Dataset

The model was trained on a dataset of Chinese-English sentence pairs. The dataset was split into training (99%) and evaluation (1%) subsets.


## Acknowledgments

- The Llama 3.2 model by Meta AI
- Unsloth for optimization techniques
- Hugging Face for the transformers library and model hosting
