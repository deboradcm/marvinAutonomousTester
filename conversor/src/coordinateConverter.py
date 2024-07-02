import random

class CoordinateConverter:
    def __init__(self, screen_width=1080, screen_height=1920, coord_range=(-10, 10)):
        """
        Inicializa a classe CoordinateConverter.
        
        Argumentos:
            screen_width (int): Largura da tela em pixels.
            screen_height (int): Altura da tela em pixels.
            coord_range (tuple): Intervalo de geração das coordenadas (min, max).
        """
        self.screen_width = screen_width
        self.screen_height = screen_height
        self.coord_range = coord_range

    def generate_random_coordinates(self):
        """
        Gera coordenadas aleatórias x, y, z.
        
        Retorna:
            tuple: Um tuple contendo as coordenadas (x, y, z).
        """
        x = random.uniform(*self.coord_range)
        y = random.uniform(*self.coord_range)
        z = random.uniform(*self.coord_range)
        return (x, y, z)

    def convert_to_pixel_coordinates(self, x, y, z):
        """
        Converte coordenadas 3D (x, y, z) para coordenadas de pixel 2D.
        
        Argumentos:
            x (float): Coordenada x.
            y (float): Coordenada y.
            z (float): Coordenada z.
        
        Retorna:
            tuple: Um tuple contendo as coordenadas de pixel (px, py).
        """
        # Normalizando as coordenadas
        x_normalized = (x - self.coord_range[0]) / (self.coord_range[1] - self.coord_range[0])
        y_normalized = (y - self.coord_range[0]) / (self.coord_range[1] - self.coord_range[0])

        # Convertendo para coordenadas de pixel
        px = int(x_normalized * self.screen_width)
        py = int(y_normalized * self.screen_height)

        return (px, py)
    
    #comando para executar: ~/marvinAutonomousTester/conversor/src$ python3 coordinateConverter.py 

# Exemplo de uso
converter = CoordinateConverter()
coordinates = converter.generate_random_coordinates()
print(f"Coordenadas Aleatórias: {coordinates}")

pixel_coordinates = converter.convert_to_pixel_coordinates(*coordinates)
print(f"Coordenadas em Pixels: {pixel_coordinates}")
