import random

class CoordinateConverter:
    def __init__(self, screen_width=1080, screen_height=1920, 
                 x_min=-35.495777, x_max=35.495777,
                 y_min=-3.872530, y_max=3.872530,
                 z_min=-71.830040, z_max=71.830040):
        """
        Inicializa a classe CoordinateConverter.
        
        Argumentos:
            screen_width (int): Largura da tela em pixels.
            screen_height (int): Altura da tela em pixels.
            x_min (float): Valor mínimo da coordenada x.
            x_max (float): Valor máximo da coordenada x.
            y_min (float): Valor mínimo da coordenada y.
            y_max (float): Valor máximo da coordenada y.
            z_min (float): Valor mínimo da coordenada z.
            z_max (float): Valor máximo da coordenada z.
        """
        self.screen_width = screen_width
        self.screen_height = screen_height
        self.x_min = x_min
        self.x_max = x_max
        self.y_min = y_min
        self.y_max = y_max
        self.z_min = z_min
        self.z_max = z_max

    def generate_random_coordinates(self):
        """
        Gera coordenadas aleatórias x, y, z dentro do bounding box.
        
        Retorna:
            tuple: Um tuple contendo as coordenadas (x, y, z).
        """
        x = random.uniform(self.x_min, self.x_max)
        y = random.uniform(self.y_min, self.y_max)
        z = random.uniform(self.z_min, self.z_max)
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
        x_normalized = (x - self.x_min) / (self.x_max - self.x_min)
        y_normalized = (y - self.y_min) / (self.y_max - self.y_min)

        # Convertendo para coordenadas de pixel
        px = int(x_normalized * self.screen_width)
        py = int(y_normalized * self.screen_height)

        return (px, py)

# Exemplo de uso
converter = CoordinateConverter()
coordinates = converter.generate_random_coordinates()
print(f"Coordenadas Aleatórias: {coordinates}")

pixel_coordinates = converter.convert_to_pixel_coordinates(*coordinates)
print(f"Coordenadas em Pixels: {pixel_coordinates}")
