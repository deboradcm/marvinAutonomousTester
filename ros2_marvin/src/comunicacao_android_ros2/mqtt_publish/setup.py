from setuptools import find_packages, setup

package_name = 'mqtt_publish'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    py_modules=[
        'mqtt_publish.mqtt_pub',
    ],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=[
        'setuptools',
        'paho-mqtt',
        'rclpy',
    ],
    zip_safe=True,
    maintainer='iartes',
    maintainer_email='iartes@todo.todo',
    description='Package que recebe os dados de um servidor MQTT e publica-os em um tópico.',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'mqtt_publish = mqtt_publish.mqtt_pub:main'
        ],
    },
)
