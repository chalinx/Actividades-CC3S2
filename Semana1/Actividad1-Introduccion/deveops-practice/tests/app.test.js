const request = require('supertest');
const { app, server } = require('../src/app'); // Importa tanto la app como el servidor

describe('GET /', () => {
  
  afterAll(() => {
    server.close(); // Cierra el servidor después de que las pruebas hayan terminado
  });

  it('should return Hello, World!', async () => {
    const res = await request(app).get('/'); // Usa `app` directamente, ya que el servidor ya está corriendo
    expect(res.statusCode).toEqual(200);
    expect(res.text).toBe('Hello, World!');
  });
});
