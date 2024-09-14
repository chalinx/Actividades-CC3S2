const request = require('supertest');
const app = require('../src/app');  // Importa la app sin escuchar el puerto

describe('GET /', () => {
  it('should return Hello, World!', async () => {
    const res = await request(app).get('/');  // No necesitas app.listen aquí
    expect(res.statusCode).toEqual(200);
    expect(res.text).toBe('Hello, World!');
  });
});
