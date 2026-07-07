import subprocess
import time
import matplotlib.pyplot as plt
import pandas as pd

# CONFIGURAÇÃO DOS TESTES
# Vamos testar o grafo aumentando de 10 até 500 vértices
valores_vertices = [10, 50, 100, 200, 300, 400, 500, 1000, 5000]
tempos = []

print("Iniciando a comparação computacional...")
print("-" * 40)

for v in valores_vertices:
    # Para o Carteiro Chinês, precisamos garantir mais arestas que vértices
    # Vamos definir a quantidade de arestas como o dobro de vértices (Grafo Esparso)
    a = v * 2 
    
    # Marca o tempo inicial do cronômetro
    tempo_inicio = time.perf_counter()
    
    # Executa o seu programa C++ passando os argumentos (v e a)
    # stdout=subprocess.DEVNULL esconde os "printfs/couts" do C++ para não poluir o terminal
    subprocess.run(["./programa", str(v), str(a)], stdout=subprocess.DEVNULL)
    
    # Marca o tempo final
    tempo_fim = time.perf_counter()
    
    tempo_total_ms = (tempo_fim - tempo_inicio) * 1000 # Converte para milissegundos
    tempos.append(tempo_total_ms)
    
    print(f"Vértices: {v} | Arestas: {a} -> Tempo: {tempo_total_ms:.2f} ms")

print("-" * 40)
print("Testes concluídos! Gerando gráfico...")

# CRIAÇÃO DO GRÁFICO AUTOMÁTICO
plt.figure(figsize=(10, 6))
plt.plot(valores_vertices, tempos, marker='o', linestyle='-', color='b', linewidth=2)
plt.title('Comparação Computacional - Escalonamento do Grafo', fontsize=14, fontweight='bold')
plt.xlabel('Quantidade de Vértices (V)', fontsize=12)
plt.ylabel('Tempo de Execução (Milissegundos)', fontsize=12)
plt.grid(True, linestyle='--', alpha=0.6)

# Salva o gráfico como imagem para o seu relatório
plt.savefig('grafico_desempenho.png', dpi=300)
print("Gráfico salvo com sucesso como 'grafico_desempenho.png'!")

# Mostra o gráfico na tela
plt.show()