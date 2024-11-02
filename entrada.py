import matplotlib.pyplot as plt
import matplotlib.patches as patches

# Dados de entrada
dados = [
    (1, 1, 3, 1, 3, 'Am'), (4, 1, 6, 1, 3, 'Am'), (1, 2, 3, 2, 3, 'Vd'),
    (4, 2, 4, 2, 1, 'Az'), (5, 2, 6, 2, 2, 'Vd'), (1, 3, 3, 3, 3, 'Vd'),
    (4, 3, 4, 3, 1, 'Am'), (5, 3, 5, 3, 1, 'Vm'), (6, 3, 6, 3, 1, 'Vm'),
    (1, 4, 1, 5, 2, 'Vm'), (2, 4, 2, 5, 2, 'Vm'), (3, 4, 3, 5, 2, 'Az'),
    (4, 4, 4, 5, 2, 'Vd'), (5, 4, 5, 5, 2, 'Az'), (6, 4, 6, 4, 1, 'Az'),
    (6, 5, 6, 5, 1, 'Az'), (1, 6, 3, 6, 3, 'Az'), (4, 6, 6, 6, 3, 'Az')
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
plt.title("Representação Entrada 5(especificação)")
plt.xlabel("Eixo X")
plt.ylabel("Eixo Y")
plt.show()
