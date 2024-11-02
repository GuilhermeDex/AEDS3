import matplotlib.pyplot as plt
import matplotlib.patches as patches

# Dados de entrada
dados = [
    (1, 1, 3, 1, 3, 'Am'), (4, 1, 6, 1, 3, 'Vd'), (1, 2, 3, 2, 3, 'Az'),
    (4, 2, 6, 2, 3, 'Vm'), (1, 3, 1, 3, 1, 'Vd'), (2, 3, 2, 3, 1, 'Am'),
    (3, 3, 3, 3, 1, 'Vm'), (4, 3, 4, 3, 1, 'Vd'), (5, 3, 6, 3, 2, 'Am'),
    (1, 4, 2, 4, 2, 'Az'), (3, 4, 4, 4, 2, 'Am'), (5, 4, 6, 4, 2, 'Vd'),
    (1, 5, 3, 5, 3, 'Vm'), (4, 5, 6, 5, 3, 'Az'), (1, 6, 3, 6, 3, 'Az'),
    (4, 6, 6, 6, 3, 'Am')
]

# Mapeamento de cor
cor_map = {'Am': 'yellow', 'Vd': 'green', 'Az': 'blue', 'Vm': 'red'}

# Configuração do plano
fig, ax = plt.subplots()
ax.set_xlim(0, 7)
ax.set_ylim(0, 7)
ax.set_xticks(range(1, 7))
ax.set_yticks(range(1, 7))
ax.grid(True, color='black', linestyle='--', linewidth=0.5)  # Configura o quadriculado

# Define o aspecto para manter as células quadradas
ax.set_aspect('equal')

# Adiciona os retângulos
for x_ini, y_ini, x_fim, y_fim, _, cor in dados:
    largura = abs(x_fim - x_ini) + 1
    altura = abs(y_fim - y_ini) + 1
    ax.add_patch(patches.Rectangle((x_ini - 0.5, y_ini - 0.5), largura, altura, color=cor_map[cor], ec='black'))

# Exibição do gráfico com eixos cartesianos
plt.title("Representação Entrada 4")
plt.xlabel("Eixo X")
plt.ylabel("Eixo Y")
plt.show()

